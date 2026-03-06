#include <stdio.h>
#include <stdbool.h>

#include "tm.h"

#define M_PI 3.1415

#define TEST(fun) \
    do { \
        if ((fun)()) { printf("### Test failed.\n"); return 1; } \
    } while (0);


bool test_mat3f_identity() {

    printf("### Testing mat3f identity...\n");

    mat3f m = mat3f_identity();

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int expected = i == j ? 1 : 0;
            if (m.data[i * 3 + j] != expected) return true;
        }
    }

    return false;
}

bool test_mat3f_add() {

    printf("### Testing mat3f add...\n");

    mat3f a = {{1, 2, 3, 3, 2, 1, 1, 2, 3}};
    mat3f b = {{4, 5, 6, 6, 5, 4, 4, 6, 5}};

    mat3f m = mat3f_add(a, b);

    if (m.data[0] != 5) return true; 
    if (m.data[1] != 7) return true; 
    if (m.data[2] != 9) return true; 
    if (m.data[3] != 9) return true; 
    if (m.data[4] != 7) return true; 
    if (m.data[5] != 5) return true; 
    if (m.data[6] != 5) return true; 
    if (m.data[7] != 8) return true; 
    if (m.data[8] != 8) return true; 

    return false;
}

bool test_mat3f_sub() {

    printf("### Testing mat3f sub...\n");

    mat3f a = {{1, 2, 3, 3, 2, 1, 1, 2, 3}};
    mat3f b = {{4, 5, 6, 6, 5, 4, 4, 6, 5}};

    mat3f m = mat3f_sub(a, b);

    if (m.data[0] != -3) return true; 
    if (m.data[1] != -3) return true; 
    if (m.data[2] != -3) return true; 
    if (m.data[3] != -3) return true; 
    if (m.data[4] != -3) return true; 
    if (m.data[5] != -3) return true; 
    if (m.data[6] != -3) return true; 
    if (m.data[7] != -4) return true; 
    if (m.data[8] != -2) return true; 

    return false;
}

bool test_mat3f_mul() {

    printf("### Testing mat3f mul...\n");

    mat3f a = {{1, 2, 3, 3, 2, 1, 1, 2, 3}};
    mat3f b = {{4, 5, 6, 6, 5, 4, 4, 6, 5}};

    mat3f m = mat3f_mul(a, b);

    if (m.data[0] != 28) return true; 
    if (m.data[1] != 33) return true; 
    if (m.data[2] != 29) return true; 
    if (m.data[3] != 28) return true; 
    if (m.data[4] != 31) return true; 
    if (m.data[5] != 31) return true; 
    if (m.data[6] != 28) return true; 
    if (m.data[7] != 33) return true; 
    if (m.data[8] != 29) return true; 

    return false;
}

bool test_mat3f_translate() {

    printf("### Testing mat3f translate...\n");

    mat3f a = {{1, 2, 3,
                3, 2, 1,
                1, 2, 3}};

    vec2f t = {2, 3};

    mat3f m = mat3f_translate(a, t);

    if (m.data[0] != 1) return true;
    if (m.data[1] != 2) return true;
    if (m.data[2] != 11) return true;

    if (m.data[3] != 3) return true;
    if (m.data[4] != 2) return true;
    if (m.data[5] != 13) return true;

    if (m.data[6] != 1) return true;
    if (m.data[7] != 2) return true;
    if (m.data[8] != 11) return true;

    return false;
}

bool test_mat3f_scaling() {

    printf("### Testing mat3f scaling...\n");

    vec2f s = {2,3};

    mat3f m = mat3f_scaling(s);

    if (m.data[0] != 2) return true;
    if (m.data[4] != 3) return true;

    return false;
}

bool test_mat3f_rotation_z() {

    printf("### Testing mat3f rotation_z...\n");

    mat3f r = mat3f_rotation_z(M_PI/2);

    vec2f v = {1,0};

    vec2f out = vec2f_transform(r, v);

    if (fabs(out.x) > 0.001f) return true;
    if (fabs(out.y - 1) > 0.001f) return true;

    return false;
}

int main(void) {
    printf("\n");

    TEST(test_mat3f_identity);
    TEST(test_mat3f_add);
    TEST(test_mat3f_sub);
    TEST(test_mat3f_mul);
    TEST(test_mat3f_translate);
    TEST(test_mat3f_scaling);
    TEST(test_mat3f_rotation_z);

    printf("\nAll tests passed. Bye!\n\n");

    return 0;
}
