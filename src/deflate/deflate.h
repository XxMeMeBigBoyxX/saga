#pragma once

#include <stdint.h>

#include "decomp.h"

C_API_START

struct DEFHUFFMAN {
    uint16_t fastLookup[512];
    uint16_t firstCode[17];
    int32_t baseCode[16];
    uint16_t numCodes[16];
    uint8_t symbols[288];
    uint16_t symbolIndex[288];
};
typedef struct DEFHUFFMAN DEFHUFFMAN;

struct DEFLATECONTEXT {
    uint8_t *readBuffer;
    uint8_t *readBufferEnd;
    int32_t numBitsAvailable;
    uint32_t bitBuffer;
    char *currentPos;
    char *startPos;
    char *endPos;
    DEFHUFFMAN lengthTree;
    DEFHUFFMAN distanceTree;
    DEFHUFFMAN tempCodeLength;
};
typedef struct DEFLATECONTEXT DEFLATECONTEXT;

int32_t ExplodeBufferNoHeader(uint8_t *param_1, uint8_t *param_2, int32_t param_3, int32_t param_4);

int32_t InflateBuffer(char *buffer, int decodedSize, char *readBuffer, int32_t readBufferSize);

int32_t ExplodeBufferSize(uint8_t *buf);

int32_t ExplodeCompressedSize(uint8_t *buffer);

C_API_END

#ifdef __cplusplus

int32_t ImplodeGetI(uint8_t *buffer, int32_t size);
void InitHuffmanDefaults(void);
int DecodeDeflated(DEFLATECONTEXT *ctx);
int32_t Inflate(DEFLATECONTEXT *ctx, char *buffer, int32_t size);
uint32_t BuildHuffmanTree(DEFHUFFMAN *tree, uint8_t *codeLengths, int32_t symbolCount);
bool DecompressHuffmanTrees(DEFLATECONTEXT *ctx);

#endif
