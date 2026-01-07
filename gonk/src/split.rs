use crate::config::{Config, ObjDiff, ObjDiffUnit};
use object::read::elf::ElfFile32;
use object::write::{Object, Symbol, SymbolSection};
use object::{
    Architecture, BinaryFormat, Endianness, Object as _, ObjectSection, ObjectSymbol, SectionKind,
    SymbolFlags, SymbolKind, SymbolScope,
};
use std::collections::HashMap;
use std::fs;
use std::path::Path;

#[derive(Debug, thiserror::Error)]
pub enum SplitError {
    #[error("Failed to read file: {0}")]
    Io(#[from] std::io::Error),
    #[error("Failed to parse TOML: {0}")]
    Toml(#[from] toml::de::Error),
    #[error("Failed to parse ELF: {0}")]
    Elf(#[from] object::read::Error),
    #[error("Symbol not found: {0}")]
    SymbolNotFound(String),
    #[error("Section not found for symbol: {0}")]
    SectionNotFound(String),
    #[error("Failed to write object file: {0}")]
    Write(#[from] object::write::Error),
    #[error("Failed to write JSON file: {0}")]
    WriteJson(#[from] serde_json::Error),
}

pub fn split() -> Result<(), SplitError> {
    let config: Config = toml::from_str(&fs::read_to_string("gonk.toml")?)?;
    let file_data = fs::read(&config.target)?;
    let elf: ElfFile32 = ElfFile32::parse(&*file_data)?;

    // cache symbols by name
    let mut syms = HashMap::new();
    for sym in elf.symbols() {
        if let Ok(name) = sym.name() {
            if !name.is_empty() {
                syms.insert(name, sym);
            }
        }
    }

    println!(
        "Loaded {} symbols from {}",
        syms.len(),
        config.target.display()
    );

    // generate unit object files
    for unit in &config.unit {
        println!("\nProcessing unit: {}", unit.path.display());
        let mut obj = Object::new(BinaryFormat::Elf, Architecture::I386, Endianness::Little);
        let mut sections: HashMap<&str, _> = HashMap::new();
        let mut offsets: HashMap<&str, u64> = HashMap::new();

        for sym_name in &unit.symbols {
            let sym = syms
                .get(sym_name.as_str())
                .ok_or_else(|| SplitError::SymbolNotFound(sym_name.clone()))?;

            // find the section containing this symbol
            let section = elf
                .sections()
                .find(|s| sym.address() >= s.address() && sym.address() < s.address() + s.size())
                .ok_or_else(|| SplitError::SectionNotFound(sym_name.clone()))?;

            let sec_name = section.name().unwrap_or("");
            let sec_kind = section.kind();
            let is_bss = sec_kind == SectionKind::UninitializedData;

            // get or create section in output
            let section_id = *sections.entry(sec_name).or_insert_with(|| {
                obj.add_section(Vec::new(), sec_name.as_bytes().to_vec(), sec_kind)
            });
            let offset = offsets.entry(sec_name).or_insert(0);

            // add data
            if is_bss {
                obj.append_section_bss(section_id, sym.size(), 1); // in ELF, bss is a section with no data at all in the file
            } else {
                let data_offset = (sym.address() - section.address()) as usize;
                let data =
                    &section.data().unwrap_or(&[])[data_offset..data_offset + sym.size() as usize];
                obj.append_section_data(section_id, data, 1);
            }

            // add symbol to output
            obj.add_symbol(Symbol {
                name: sym_name.as_bytes().to_vec(),
                value: *offset,
                size: sym.size(),
                kind: if sec_kind == SectionKind::Text {
                    SymbolKind::Text
                } else {
                    SymbolKind::Data
                },
                scope: SymbolScope::Dynamic,
                weak: false,
                section: SymbolSection::Section(section_id),
                flags: SymbolFlags::None,
            });

            println!(
                "  {} @ 0x{:08x} ({} bytes, {})",
                sym_name,
                sym.address(),
                sym.size(),
                sec_name
            );
            *offset += sym.size(); // make sure to increment the offset for the next symbol
        }

        let output_path = Path::new("units").join(unit.path.with_added_extension("o"));
        fs::create_dir_all(output_path.parent().unwrap())?; // create the directory for the output file if it doesn't exist
        fs::write(&output_path, obj.write()?)?;
        println!("Wrote processed unit: {}", output_path.display());
    }

    // generate objdiff.json file
    let mut objdiff = ObjDiff {
        build_base: false,
        build_target: false,
        units: Vec::new(),
    };

    // add units to objdiff
    for unit in &config.unit {
        objdiff.units.push(ObjDiffUnit {
            name: unit.path.display().to_string(),
            // repeating myself a bit here, but it's ok for now :)
            target_path: Path::new("units").join(unit.path.with_added_extension("o")),
            base_path: Path::new("build/CMakeFiles/saga.dir/src").join(unit.path.with_added_extension("o")),
        });
    }

    fs::write("objdiff.json", serde_json::to_string_pretty(&objdiff)?)?;
    println!("\nWrote objdiff.json");
    Ok(())
}
