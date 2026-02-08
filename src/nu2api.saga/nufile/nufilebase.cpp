#include "nu2api.saga/nufile/nufile.h"

#include "nu2api.saga/nucore/nustring.h"

i32 NuFile::IFile::GetCapabilities() const {
}

const char *NuFile::IFile::GetFilename() const {
}

u32 NuFile::IFile::GetType() const {
}

void NuFile::IFile::Seek(i64 offset, NuFile::SeekOrigin::T) {
}

isize NuFile::IFile::Read(void *buf, usize size) {
}

isize NuFile::IFile::Write(const void *buf, usize size) {
}

usize NuFile::IFile::GetPos() const {
}

i64 NuFile::IFile::GetSize() const {
}

void NuFile::IFile::Close() {
}

void NuFile::IFile::Flush() {
}

NuFileBase::NuFileBase(const char *filepath, NuFile::OpenMode::T mode, u32 type) {
    this->type = type;
    this->mode = mode;
    this->unknown = 0;

    NuStrNCpy(this->filepath, filepath, sizeof(this->filepath));
}

i32 NuFileBase::GetCapabilities() const {
    return 0;
}

const char *NuFileBase::GetFilename() const {
    return this->filepath;
}

u32 NuFileBase::GetType() const {
    return this->type;
}

usize NuFileBase::GetPos() const {
    return 0;
}

i64 NuFileBase::GetSize() const {
    return 0;
}

void NuFileBase::Flush() {
}
