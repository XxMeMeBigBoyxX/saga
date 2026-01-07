use std::path::PathBuf;
use serde::{Deserialize, Serialize};

#[derive(Debug, Serialize, Deserialize)]
pub struct Config {
    pub target: PathBuf,
    pub unit: Vec<Unit>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct Unit {
    pub path: PathBuf,
    pub symbols: Vec<String>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ObjDiff {
    pub build_base: bool,
    pub build_target: bool, 
    pub units: Vec<ObjDiffUnit>,
}

#[derive(Debug, Serialize, Deserialize)]
pub struct ObjDiffUnit {
    pub name: String,
    pub target_path: PathBuf,
    pub base_path: PathBuf,
}