#ifndef NU2API_SAGA_NU3D_NUSHADER_H
#define NU2API_SAGA_NU3D_NUSHADER_H

#include <GLES2/gl2.h>

struct nushaderobjectkey_s {

};

typedef struct nushaderobjectkey_s NUSHADEROBJECTKEY;

struct nushaderobjectbase_s {
    int field0;
    int field1;
    // this is a NUSHADEROBJECTKEY*, but for some reason they store it as an int
    // if it isn't an int then SSE instructions aren't generated and it doesn't match
    int key;
    int field3;
};

typedef struct nushaderobjectbase_s NUSHADEROBJECTBASE;

typedef struct nushaderobjectbase_s NUSHADEROBJECTBASE;
struct nushaderobjectglsl_s {
    NUSHADEROBJECTBASE base;
    GLuint program;
    GLuint vertex_shader;
    GLuint fragment_shader;
};

typedef struct nushaderobjectglsl_s NUSHADEROBJECTGLSL;

#define NUSHADEROBJECT_UNKS_COUNT 91
struct nushaderobject_s {
    NUSHADEROBJECTGLSL glsl;
    char unk[0x10];
    struct {
        short unk1;
        short unk2;
        char unk3;
        char unk4[3];
    } unks[NUSHADEROBJECT_UNKS_COUNT]; // maybe these are uniforms?
};

typedef nushaderobject_s NUSHADEROBJECT;

#ifdef __cplusplus
int NuShaderObjectBindAttributeLocationsGLSL(GLuint program);
int NuShaderObjectCombineGLSLShadersIntoProgram(GLuint* program_dest, GLuint vertex_shader, GLuint fragment_shader);

extern "C" {
#endif

void NuShaderObjectBaseCreate(NUSHADEROBJECTBASE* shader);
void NuShaderObjectGLSLCreate(NUSHADEROBJECTGLSL* shader);
void NuShaderObjectCreate(NUSHADEROBJECT* shader);
void NuShaderObjectBaseDestroy(NUSHADEROBJECTBASE* shader);
void NuShaderObjectGLSLDestroy(NUSHADEROBJECTGLSL* shader);
void NuShaderObjectDestroy(NUSHADEROBJECT* shader);
void NuShaderObjectBaseInit(NUSHADEROBJECTBASE* shader, NUSHADEROBJECTKEY* key, int unk);
void NuShaderObjectUnInit(NUSHADEROBJECT* shader);
void NuShaderObjectBaseUnInit(NUSHADEROBJECTBASE* shader);
void NuShaderObjectBaseSetWaterSpeed(float speed);

#ifdef __cplusplus
}
#endif

#endif // NU2API_SAGA_NU3D_NUSHADER_H