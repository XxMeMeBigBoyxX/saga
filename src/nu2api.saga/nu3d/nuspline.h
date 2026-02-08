#include "nu2api.saga/nucore/common.h"
#include "nu2api.saga/numath/nuvec.h"

typedef struct nugspline_s {
    u16 length;
    u16 pt_size;
    char *name;

    // This seems to be typed as `char *` in the original code base, but use as
    // a `NUVEC` is all but hardcoded.
    NUVEC *pts;
} NUGSPLINE;

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
}
#endif
