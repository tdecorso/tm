#ifndef H_TM
#define H_TM

#include <assert.h>
#include <math.h>

typedef struct vec2i {
    int x;
    int y;
} vec2i;

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

static int vec2i_len(vec2i a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

static vec2i vec2i_norm(vec2i a) {
    return vec2i_div(a, vec2i_len(a));
}

#endif // H_TM
