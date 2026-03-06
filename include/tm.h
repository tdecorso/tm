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

typedef struct mat3i {
    int data[9];
} mat3i;

typedef struct mat3f {
    float data[9];
} mat3f;

#define MAT3_AT(m, i, j) ((m).data[(i)*3+(j)])

static vec2i vec2i_add(vec2i a, vec2i b) {
    return (vec2i) {a.x + b.x, a.y + b.y};
}

static vec2i vec2i_sub(vec2i a, vec2i b) {
    return (vec2i) {a.x - b.x, a.y - b.y};
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
    return sqrtf(a.x * a.x + a.y * a.y);
}

static vec2f vec2f_norm(vec2f a) {
    float len = vec2f_len(a);
    if (len == 0.0f) return a;
    return vec2f_div(a, len);
}

static vec3i vec3i_add(vec3i a, vec3i b) {
    return (vec3i) {a.x + b.x, a.y + b.y, a.z + b.z};
}

static vec3i vec3i_sub(vec3i a, vec3i b) {
    return (vec3i) {a.x - b.x, a.y - b.y, a.z - b.z};
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

static float vec3f_dot(vec3f a, vec3f b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

static float vec3f_len(vec3f a) {
    return sqrtf(a.x * a.x + a.y * a.y + a.z * a.z);
}

static vec3f vec3f_norm(vec3f a) {
    float len = vec3f_len(a);
    if (len == 0.0f) return a;
    return vec3f_div(a, len);
}

static vec3f vec3f_cross(vec3f a, vec3f b) {
    return (vec3f) {a.y*b.z - a.z*b.y, a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x};
}

static mat3i mat3i_identity() {
    mat3i m = {0};

    MAT3_AT(m, 0, 0) = 1;
    MAT3_AT(m, 1, 1) = 1;
    MAT3_AT(m, 2, 2) = 1;

    return m;
}

static mat3i mat3i_add(mat3i a, mat3i b) {
    mat3i m = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            MAT3_AT(m, i, j) = MAT3_AT(a, i, j) + MAT3_AT(b, i, j);
        }
    }

    return m;
}

static mat3i mat3i_sub(mat3i a, mat3i b) {
    mat3i m = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int index = i * 3 + j;
            MAT3_AT(m, i, j) = MAT3_AT(a, i, j) - MAT3_AT(b, i, j);
        }
    }

    return m;
}

static mat3f mat3f_identity() {
    mat3f m = {0};

    MAT3_AT(m, 0, 0) = 1;
    MAT3_AT(m, 1, 1) = 1;
    MAT3_AT(m, 2, 2) = 1;

    return m;
}

static mat3f mat3f_add(mat3f a, mat3f b) {
    mat3f m = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            MAT3_AT(m, i, j) = MAT3_AT(a, i, j) + MAT3_AT(b, i, j);
        }
    }

    return m;
}

static mat3f mat3f_sub(mat3f a, mat3f b) {
    mat3f m = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            MAT3_AT(m, i, j) = MAT3_AT(a, i, j) - MAT3_AT(b, i, j);
        }
    }

    return m;
}

static mat3f mat3f_mul(mat3f a, mat3f b) {
    mat3f m = {0};

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            float total = 0;
            for (int k = 0; k < 3; ++k) {
                total += MAT3_AT(a, i, k) * MAT3_AT(b, k, j);
            }
            MAT3_AT(m, i, j) = total;
        }
    }

    return m;
}

static mat3f mat3f_translation(vec2f t)
{
    mat3f m = mat3f_identity();

    MAT3_AT(m, 0, 2) = t.x;
    MAT3_AT(m, 1, 2) = t.y;

    return m;
}

static mat3f mat3f_translate(mat3f a, vec2f t)
{
    return mat3f_mul(a, mat3f_translation(t));
}

static mat3f mat3f_scaling(vec2f s) {

    mat3f m = mat3f_identity();

    MAT3_AT(m, 0, 0) = s.x;
    MAT3_AT(m, 1, 1) = s.y;

    return m;
}

static mat3f mat3f_scale(mat3f a, vec2f s) {
    return mat3f_mul(a, mat3f_scaling(s));
}

static mat3f mat3f_rotation_x(float angle) {
    mat3f m = mat3f_identity();

    MAT3_AT(m, 1, 1) =  cosf(angle);
    MAT3_AT(m, 1, 2) = -sinf(angle);
    MAT3_AT(m, 2, 1) =  sinf(angle);
    MAT3_AT(m, 2, 2) =  cosf(angle);

    return m;
}

static mat3f mat3f_rotation_y(float angle) {
    mat3f m = mat3f_identity();


    MAT3_AT(m, 0, 0) =  cosf(angle);
    MAT3_AT(m, 0, 2) =  sinf(angle);
    MAT3_AT(m, 2, 0) = -sinf(angle);
    MAT3_AT(m, 2, 2) =  cosf(angle);

    return m;
}

static mat3f mat3f_rotation_z(float angle) {
    mat3f m = mat3f_identity();

    MAT3_AT(m, 0, 0) =  cosf(angle);
    MAT3_AT(m, 0, 1) = -sinf(angle);
    MAT3_AT(m, 1, 0) =  sinf(angle);
    MAT3_AT(m, 1, 1) =  cosf(angle);

    return m;
}

static mat3f mat3f_rotate_x(mat3f a, float angle) {
    mat3f r = mat3f_rotation_x(angle);
    return mat3f_mul(a, r);
}

static mat3f mat3f_rotate_y(mat3f a, float angle) {
    mat3f r = mat3f_rotation_y(angle);
    return mat3f_mul(a, r);
}

static mat3f mat3f_rotate_z(mat3f a, float angle) {
    mat3f r = mat3f_rotation_z(angle);
    return mat3f_mul(a, r);
}

static vec2f vec2f_transform(mat3f a, vec2f v) {
    vec2f result;

    result.x = MAT3_AT(a, 0, 0) * v.x + 
               MAT3_AT(a, 0, 1) * v.y + 
               MAT3_AT(a, 0, 2);

    result.y = MAT3_AT(a, 1, 0) * v.x + 
               MAT3_AT(a, 1, 1) * v.y + 
               MAT3_AT(a, 1, 2);

    return result;
}

static mat3f mat3f_transform(vec2f t, float angle, vec2f s)
{
    mat3f m = mat3f_identity();

    float c = cosf(angle);
    float si = sinf(angle);

    MAT3_AT(m,0,0) =  s.x * c;
    MAT3_AT(m,0,1) = -s.y * si;
    MAT3_AT(m,1,0) =  s.x * si;
    MAT3_AT(m,1,1) =  s.y * c;

    MAT3_AT(m,0,2) = t.x;
    MAT3_AT(m,1,2) = t.y;

    return m;
}

#endif // H_TM
