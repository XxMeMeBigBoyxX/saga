#pragma once

#include <stdint.h>

#include "decomp.h"
#include "export.h"

C_API_START

struct episodedata_s {
    int32_t _0;
    int16_t areaIds[10];
    int8_t areaCount;
};
typedef struct episodedata_s EPISODEDATA;

enum areaflags_e {
    AREAFLAG_NO_GOLDBRICK = 0x800,
};
typedef enum areaflags_e AREAFLAGS;

struct areadata_s { /* PlaceHolder Structure */
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
    undefined field16_0x10;
    undefined field17_0x11;
    undefined field18_0x12;
    undefined field19_0x13;
    undefined field20_0x14;
    undefined field21_0x15;
    undefined field22_0x16;
    undefined field23_0x17;
    undefined field24_0x18;
    undefined field25_0x19;
    undefined field26_0x1a;
    undefined field27_0x1b;
    undefined field28_0x1c;
    undefined field29_0x1d;
    undefined field30_0x1e;
    undefined field31_0x1f;
    undefined field32_0x20;
    undefined field33_0x21;
    undefined field34_0x22;
    undefined field35_0x23;
    undefined field36_0x24;
    undefined field37_0x25;
    undefined field38_0x26;
    undefined field39_0x27;
    undefined field40_0x28;
    undefined field41_0x29;
    undefined field42_0x2a;
    undefined field43_0x2b;
    undefined field44_0x2c;
    undefined field45_0x2d;
    undefined field46_0x2e;
    undefined field47_0x2f;
    undefined field48_0x30;
    undefined field49_0x31;
    undefined field50_0x32;
    undefined field51_0x33;
    undefined field52_0x34;
    undefined field53_0x35;
    undefined field54_0x36;
    undefined field55_0x37;
    undefined field56_0x38;
    undefined field57_0x39;
    undefined field58_0x3a;
    undefined field59_0x3b;
    undefined field60_0x3c;
    undefined field61_0x3d;
    undefined field62_0x3e;
    undefined field63_0x3f;
    undefined field64_0x40;
    undefined field65_0x41;
    undefined field66_0x42;
    undefined field67_0x43;
    undefined field68_0x44;
    undefined field69_0x45;
    undefined field70_0x46;
    undefined field71_0x47;
    undefined field72_0x48;
    undefined field73_0x49;
    undefined field74_0x4a;
    undefined field75_0x4b;
    undefined field76_0x4c;
    undefined field77_0x4d;
    undefined field78_0x4e;
    undefined field79_0x4f;
    undefined field80_0x50;
    undefined field81_0x51;
    undefined field82_0x52;
    undefined field83_0x53;
    undefined field84_0x54;
    undefined field85_0x55;
    undefined field86_0x56;
    undefined field87_0x57;
    undefined field88_0x58;
    undefined field89_0x59;
    undefined field90_0x5a;
    undefined field91_0x5b;
    undefined field92_0x5c;
    undefined field93_0x5d;
    undefined field94_0x5e;
    undefined field95_0x5f;
    undefined field96_0x60;
    undefined field97_0x61;
    undefined field98_0x62;
    undefined field99_0x63;
    undefined field100_0x64;
    undefined field101_0x65;
    undefined field102_0x66;
    undefined field103_0x67;
    undefined field104_0x68;
    undefined field105_0x69;
    undefined field106_0x6a;
    undefined field107_0x6b;
    undefined field108_0x6c;
    undefined field109_0x6d;
    undefined field110_0x6e;
    undefined field111_0x6f;
    undefined field112_0x70;
    undefined field113_0x71;
    undefined field114_0x72;
    undefined field115_0x73;
    undefined field116_0x74;
    undefined field117_0x75;
    undefined field118_0x76;
    undefined field119_0x77;
    undefined field120_0x78;
    undefined field121_0x79;
    AREAFLAGS flags;
    undefined field123_0x7c;
    undefined field124_0x7d;
    byte cheat;
    undefined field126_0x7f;
    int field127_0x80;
    short field128_0x84;
    byte episodeIndex;
    byte areaIndex;
    short areaMusic;
    undefined2 minikitId;
    undefined4 field133_0x8c;
    undefined4 field134_0x90;
    undefined field135_0x94;
    undefined field136_0x95;
    undefined field137_0x96;
    undefined field138_0x97;
    undefined field139_0x98;
    undefined field140_0x99;
    undefined field141_0x9a;
    undefined field142_0x9b;
};
typedef struct areadata_s AREADATA;

struct cheat_s { /* PlaceHolder Structure */
    char *name;
    undefined field1_0x4;
    undefined field2_0x5;
    undefined field3_0x6;
    undefined field4_0x7;
    byte enabled; /* Created by retype action */
    undefined field6_0x9;
    undefined field7_0xa;
    uint8_t area;
    undefined field9_0xc;
    undefined field10_0xd;
    undefined field11_0xe;
    undefined field12_0xf;
    char *code;
    undefined field14_0x14;
    undefined field15_0x15;
    undefined field16_0x16;
    undefined field17_0x17;
    char *extraName;
    uint flag;
};
typedef struct cheat_s CHEAT;

struct cheatsystem_s {
    CHEAT *cheats;
    int cheatsCount;
    int flags;
    undefined field3_0xc;
    undefined field4_0xd;
    undefined field5_0xe;
    undefined field6_0xf;
};
typedef struct cheatsystem_s CHEATSYSTEM;

struct LEVELDATADISPLAY { /* PlaceHolder Structure */
    undefined field0_0x0;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    int64_t field8_0x8;
    float field9_0x10;
    short field10_0x14;
    undefined field11_0x16;
    undefined field12_0x17;
    undefined field13_0x18;
    undefined field14_0x19;
    undefined field15_0x1a;
    undefined field16_0x1b;
};

enum levelflags_e {
    LEVEL_INTRO = 32,
    LEVEL_MIDTRO = 64,
    LEVEL_OUTRO = 128,
    LEVEL_TEST = 512,
    LEVEL_STATUS = 1024,
    LEVEL_NEWGAME = 65536,
    LEVEL_LOADGAME = 131072
};
typedef enum levelflags_e LEVELFLAGS;

struct leveldata_s { /* PlaceHolder Structure */
    char dir[64];
    char name[32]; /* Created by retype action */
    undefined2 field2_0x60;
    undefined2 field3_0x62;
    LEVELFLAGS flags;
    void *loadFn;
    void *initFn;
    void *resetFn; /* Created by retype action */
    void *updateFn;
    void *alwaysUpdateFn;
    void *drawFn;
    void *drawStatusFn;
    struct LEVELDATADISPLAY field12_0x84;
    short musicIndex;
    undefined2 field14_0xa2;
    undefined2 field15_0xa4;
    undefined2 field16_0xa6;
    undefined2 field17_0xa8;
    undefined2 field18_0xaa;
    undefined1 field19_0xac;
    undefined1 field20_0xad;
    undefined1 field21_0xae;
    undefined1 field22_0xaf;
    undefined4 field23_0xb0;
    undefined4 field24_0xb4;
    undefined1 field25_0xb8;
    undefined1 field26_0xb9;
    undefined1 field27_0xba;
    undefined1 field28_0xbb;
    undefined1 field29_0xbc;
    undefined1 field30_0xbd;
    undefined1 field31_0xbe;
    undefined1 field32_0xbf;
    float field33_0xc0;
    undefined4 field34_0xc4;
    undefined4 field35_0xc8;
    undefined4 field36_0xcc;
    undefined field37_0xd0;
    undefined field38_0xd1;
    undefined field39_0xd2;
    undefined field40_0xd3;
    undefined1 field41_0xd4;
    byte field42_0xd5;
    byte field43_0xd6;
    undefined1 field44_0xd7;
    undefined1 field45_0xd8;
    undefined1 field46_0xd9;
    undefined1 field47_0xda;
    undefined1 field48_0xdb;
    float field49_0xdc;
    float field50_0xe0;
    int field51_0xe4;
    undefined4 field52_0xe8;
    undefined4 field53_0xec;
    undefined4 field54_0xf0;
    undefined1 field55_0xf4;
    undefined1 field56_0xf5;
    undefined1 field57_0xf6;
    undefined1 field58_0xf7;
    undefined1 field59_0xf8;
    undefined1 field60_0xf9;
    undefined1 field61_0xfa;
    byte max_obstacles;
    undefined1 field63_0xfc;
    undefined1 field64_0xfd;
    undefined1 field65_0xfe;
    undefined1 field66_0xff;
    undefined1 field67_0x100;
    undefined1 field68_0x101;
    undefined1 field69_0x102;
    undefined1 field70_0x103;
    undefined1 field71_0x104;
    undefined1 field72_0x105;
    undefined1 field73_0x106;
    undefined1 field74_0x107;
    undefined1 field75_0x108;
    undefined1 field76_0x109;
    undefined1 field77_0x10a;
    undefined1 field78_0x10b;
    undefined1 field79_0x10c;
    undefined1 field80_0x10d;
    undefined1 field81_0x10e;
    undefined1 field82_0x10f;
    undefined1 field83_0x110;
    undefined1 field84_0x111;
    undefined1 field85_0x112;
    byte max_bombgens;
    undefined1 field87_0x114;
    undefined1 field88_0x115;
    undefined field89_0x116;
    undefined field90_0x117;
    undefined2 field91_0x118;
    undefined field92_0x11a;
    undefined field93_0x11b;
    float field94_0x11c;
    float field95_0x120;
    undefined4 field96_0x124;
    undefined4 field97_0x128;
    int musicTracks[6];
};
typedef struct leveldata_s LEVELDATA;

extern CHEATSYSTEM CheatSystem;

extern AREADATA *ADataList;
extern LEVELDATA *LDataList;
extern EPISODEDATA *EDataList;

extern AREADATA *HUB_ADATA;

extern int32_t PAL;
extern float FRAMETIME;
extern float DEFAULTFPS;
extern float DEFAULTFRAMETIME;
extern float MAXFRAMETIME;

extern int32_t SUPERBUFFERSIZE;
extern void *permbuffer_base;
extern void *original_permbuffer_base;
extern void *superbuffer_end;
extern void *permbuffer_ptr;
extern void *permbuffer_end;

extern char prodcode[16];
extern char *iconname;
extern char unicodename[64];

extern int32_t EPISODECOUNT;
extern int32_t AREACOUNT;
extern int32_t LEVELCOUNT;

extern GAMESAVE_s Game;

extern int32_t COMPLETIONPOINTS;
extern int32_t POINTS_PER_CHARACTER;
extern int32_t POINTS_PER_SUPERBONUSCOMPLETE;
extern int32_t POINTS_PER_TIMETRIAL;
extern int32_t POINTS_PER_STORY;
extern int32_t POINTS_PER_CHALLENGE;
extern int32_t POINTS_PER_MINIKIT;
extern int32_t POINTS_PER_TRUEJEDI;
extern int32_t POINTS_PER_REDBRICK;
extern int32_t POINTS_PER_MISSION;
extern int32_t POINTS_PER_CHEAT;
extern int32_t POINTS_PER_GOLDBRICK;
extern int32_t BOTHTRUEJEDIGOLDBRICKS;
extern int32_t SHOPGOLDBRICKS;
extern int32_t GOLDBRICKFORSUPERBONUS;
extern int32_t GOLDBRICKFORSUPERSTORY;
extern int32_t GOLDBRICKFORCHALLENGE;
extern int32_t POINTS_PER_SUPERSTORY;
extern int32_t GOLDBRICKPOINTS;

extern int32_t CompletionPointInfo[7];

C_API_END