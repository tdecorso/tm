#ifndef H_TM
#define H_TM

#include <assert.h>
#include <math.h>

typedef struct vec2i {
    int x;
    int y;
} vec2i;

typedef struct vec2f {
    float x;
    float y;
} vec2f;

typedef struct vec3i {
    int x;
    int y;
    int z;
} vec3i;

typedef struct vec3f {
    float x;
    float y;
    float z;
} vec3f;

static vec2i vec2i_add(vec2i a, vec2i b) {
    return (vec2i) {a.x + b.x, a.y + b.y};
}

static vec2i vec2i_sub(vec2i a, vec2i b) {
    return (vec2i) {a.x - b.x, a.y - b.y};
}

static vec2i vec2i_mul(vec2i a, int factor) {
    return (vec2i) {a.x * factor, a.y * factor};
}

static vec2i vec2i_div(vec2i a, int factor) {
    assert(factor != 0);
    return (vec2i) {a.x / factor, a.y / factor};
}

static int vec2i_dot(vec2i a, vec2i b) {
    return a.x * b.x + a.y * b.y;
}

static float vec2i_len(vec2i a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

static vec2i vec2i_norm(vec2i a) {
    return vec2i_div(a, vec2i_len(a));
}

static vec2f vec2f_add(vec2f a, vec2f b) {
    return (vec2f) {a.x + b.x, a.y + b.y};
}

static vec2f vec2f_sub(vec2f a, vec2f b) {
    return (vec2f) {a.x - b.x, a.y - b.y};
}

static vec2f vec2f_mul(vec2f a, float factor) {
    return (vec2f) {a.x * factor, a.y * factor};
}

static vec2f vec2f_div(vec2f a, float factor) {
    assert(factor != 0);
    return (vec2f) {a.x / factor, a.y / factor};
}

static float vec2f_dot(vec2f a, vec2f b) {
    return a.x * b.x + a.y * b.y;
}

static float vec2f_len(vec2f a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

static vec2f vec2f_norm(vec2f a) {
    return vec2f_div(a, vec2f_len(a));
}

static vec3i vec3i_add(vec3i a, vec3i b) {
    return (vec3i) {a.x + b.x, a.y + b.y, a.z + b.z};
}

static vec3i vec3i_sub(vec3i a, vec3i b) {
    return (vec3i) {a.x - b.x, a.y - b.y, a.z - b.z};
}

static vec3i vec3i_mul(vec3i a, float factor) {
    return (vec3i) {a.x * factor, a.y * factor, a.z * factor};
}

static vec3i vec3i_div(vec3i a, float factor) {
    assert(factor != 0);
    return (vec3i) {a.x / factor, a.y / factor, a.z / factor};
}

static int vec3i_dot(vec3i a, vec3i b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static float vec3i_len(vec3i a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

static vec3i vec3i_norm(vec3i a) {
    return vec3i_div(a, vec3i_len(a));
}

static vec3i vec3i_cross(vec3i a, vec3i b) {
    return (vec3i) {a.y*b.z - a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
}

static vec3f vec3f_add(vec3f a, vec3f b) {
    return (vec3f) {a.x + b.x, a.y + b.y, a.z + b.z};
}

static vec3f vec3f_sub(vec3f a, vec3f b) {
    return (vec3f) {a.x - b.x, a.y - b.y, a.z - b.z};
}

static vec3f vec3f_mul(vec3f a, float factor) {
    return (vec3f) {a.x * factor, a.y * factor, a.z * factor};
}

static vec3f vec3f_div(vec3f a, float factor) {
    assert(factor != 0);
    return (vec3f) {a.x / factor, a.y / factor, a.z / factor};
}

static int vec3f_dot(vec3f a, vec3f b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static float vec3f_len(vec3f a) {
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

static vec3f vec3f_norm(vec3f a) {
    return vec3f_div(a, vec3f_len(a));
}

static vec3f vec3f_cross(vec3f a, vec3f b) {
    return (vec3f) {a.y*b.z - a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
}

#endif // H_TM
