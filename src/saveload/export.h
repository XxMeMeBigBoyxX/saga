typedef unsigned char undefined;

typedef unsigned char byte;
typedef unsigned char dwfenc;
typedef unsigned int dword;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef unsigned long ulong;
typedef unsigned long long ulonglong;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined3;
typedef unsigned int undefined4;
typedef unsigned long long undefined5;
typedef unsigned long long undefined6;
typedef unsigned long long undefined7;
typedef unsigned long long undefined8;
typedef unsigned short ushort;
typedef unsigned short word;
typedef struct SaveLoad SaveLoad, *PSaveLoad;

struct SaveLoad {
    int field0_0x0;
    int field1_0x4;
    int size;
    int field3_0xc;
    int field4_0x10;
    int extradataOffset;
    char field6_0x18[16];
    short field7_0x28;
    char field8_0x2a[2046];
    short field9_0x828;
    char field10_0x82a[2046];
    short field11_0x1028;
    char field12_0x102a[2046];
    short field13_0x1828;
    char field14_0x182a[2046];
};
