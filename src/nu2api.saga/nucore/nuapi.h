#ifndef NU2API_SAGA_NUCORE_NUAPI_H
#define NU2API_SAGA_NUCORE_NUAPI_H

#include "nu2api.saga/nucore/nutime.h"
#include "gamelib/nuwind.h"

enum NUVIDEO_SWAPMODE {
    NUVIDEO_SWAPMODE_INVALID = 0,
    NUVIDEO_SWAPMODE_ASYNC = 1,
    NUVIDEO_SWAPMODE_FIELDSYNC = 2,
    NUVIDEO_SWAPMODE_FRAMESYNC = 3,
    NUVIDEO_SWAPMODE_MIN2FIELD = 4,
    NUVIDEO_SWAPMODE_ROLLING = 5,
    NUVIDEO_SWAPMODE_ROLLING2FRAMES = 6,
    NUVIDEO_SWAPMODE_CNT = 7
};

typedef enum NUVIDEO_SWAPMODE NUVIDEO_SWAPMODE;

enum NUVIDEOMODE {
	NUVIDEOMODE_UNDEFINED = 0,
	NUVIDEOMODE_UNUSED1 = 1,
	NUVIDEOMODE_NTSC = 2,
	NUVIDEOMODE_PAL = 3,
	NUVIDEOMODE_PALFF = 4,
	NUVIDEOMODE_NTSCFF = 5,
	NUVIDEOMODE_NTSC_J = 6
};

typedef enum NUVIDEOMODE NUVIDEOMODE;

struct nuapi_s {
    int field0_0x0;
    NUVIDEOMODE video_mode;
    NUVIDEO_SWAPMODE swap_mode;
    int field3_0xc;
    unsigned int screen_width;
    unsigned int screen_height;
    char field6_0x18;
    char field7_0x19;
    char field8_0x1a;
    char field9_0x1b;
    float fps;
    int nuframe_begin_cnt;
    char field12_0x24;
    char field13_0x25;
    char field14_0x26;
    char field15_0x27;
    NUTIME time;
    NUTIME time2;
    float frametime;
    char field19_0x3c;
    char field20_0x3d;
    char field21_0x3e;
    char field22_0x3f;
    float forced_frame_time;
    float maxFps;
    char field25_0x48;
    char field26_0x49;
    char field27_0x4a;
    char field28_0x4b;
    char field29_0x4c;
    char field30_0x4d;
    char field31_0x4e;
    char field32_0x4f;
    char field33_0x50;
    char field34_0x51;
    char field35_0x52;
    char field36_0x53;
    char field37_0x54;
    char field38_0x55;
    char field39_0x56;
    char field40_0x57;
    int padrecBuffersize;
    char field42_0x5c;
    char field43_0x5d;
    char field44_0x5e;
    char field45_0x5f;
    char field46_0x60;
    char field47_0x61;
    char field48_0x62;
    char field49_0x63;
    int field50_0x64;
    int field51_0x68;
    char field52_0x6c;
    char field53_0x6d;
    char field54_0x6e;
    char field55_0x6f;
    char field56_0x70;
    char field57_0x71;
    char field58_0x72;
    char field59_0x73;
    char field60_0x74;
    char field61_0x75;
    char field62_0x76;
    char field63_0x77;
    NUWIND *wind;
    char field65_0x7c;
    char field66_0x7d;
    char field67_0x7e;
    char field68_0x7f;
    char field69_0x80;
    char field70_0x81;
    char field71_0x82;
    char field72_0x83;
    char field73_0x84;
    char field74_0x85;
    char field75_0x86;
    char field76_0x87;
    int field77_0x88;
    char field78_0x8c;
    char field79_0x8d;
    char field80_0x8e;
    char field81_0x8f;
};

typedef struct nuapi_s NUAPI;

extern NUAPI nuapi;

#ifdef __cplusplus
void NuAPIInit(void);

extern "C" {
#endif

    void NuCommandLine(int argc, char **argv);

#ifdef __cplusplus
}
#endif

#endif // NU2API_SAGA_NUCORE_NUAPI_H