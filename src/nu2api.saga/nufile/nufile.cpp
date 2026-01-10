#include "nu2api.saga/nufile/nufile.h"
#include "nu2api.saga/nucore/nustring.h"

extern "C" uint8_t DEV_FormatName(NuFileDevice *device, char *dest, char *path, int length) {
    LOG("device=%p, dest=%p, path=%p, length=%d", device, dest, path, length);

    int n;
    int iVar1;
    int len;
    char *prefix;
    char buf[512];
    char sep;

    prefix = device->path;
    n = NuStrLen(prefix);
    iVar1 = NuStrNICmp(path, prefix, n);
    if (iVar1 == 0) {
        iVar1 = NuStrLen(prefix);
        sep = path[iVar1];
        if ((sep == '/') || (sep == '\\')) {
            NuStrCpy(buf, path);
        } else {
            NuStrCpy(buf, device->field37_0x4c);
            NuStrCat(buf, device->field39_0xac);
            NuStrCat(buf, path + iVar1);
        }
    } else {
        NuStrCpy(buf, device->field37_0x4c);
        NuStrCat(buf, device->field39_0xac);
        NuStrCat(buf, path);
    }
    iVar1 = NuStrLen(device->field37_0x4c);
    NuFileCorrectSlashes(device, buf + iVar1);
    NuFileReldirFix(device, buf);
    len = NuStrLen(buf);
    if (len < length) {
        NuStrCpy(dest, buf);
    }

    LOG("Formatted path: %s, returning %d", buf, len < length);

    return len < length;
}