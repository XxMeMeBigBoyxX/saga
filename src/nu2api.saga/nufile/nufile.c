#include "nu2api.saga/nucore/nustring.h"
#include "nu2api.saga/nufile/nufile.h"

int DEVHOST_Interrogate(NUFILE_DEVICE *device) {
    device->status = 1;

    return 1;
}

int DEV_FormatName(NUFILE_DEVICE *device, char *formatted_name, char *path, int buf_size) {
    char buf[512];
    int device_name_len;
    char sep;
    int path_pos;
    int path_len;
    int sep_pos;

    device_name_len = NuStrLen(device->name);

    if (NuStrNICmp(path, device->name, device_name_len) == 0) {
        sep_pos = NuStrLen(device->name);

        if (path[sep_pos] == '\\' || path[sep_pos] == '/') {
            NuStrCpy(buf, path);
        } else {
            NuStrCpy(buf, device->root);
            NuStrCat(buf, device->cur_dir);
            NuStrCat(buf, path + sep_pos);
        }
    } else {
        NuStrCpy(buf, device->root);
        NuStrCat(buf, device->cur_dir);
        NuStrCat(buf, path);
    }

    path_pos = NuStrLen(device->root);
    NuFileCorrectSlashes(device, path + path_pos);
    NuFileReldirFix(device, buf);

    path_len = NuStrLen(buf);
    if (buf_size > path_len) {
        NuStrCpy(formatted_name, buf);
        return 1;
    }

    return 0;
}

int32_t NuFileReadDir(NUFILE file) {
    return 0;
}
