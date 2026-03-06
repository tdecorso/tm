#include <stdio.h>
#include <stdbool.h>

#include "tm.h"

#define TEST(fun) \
    do { \
        if ((fun)()) { printf("### Test failed.\n"); return 1; } \
    } while (0);

bool test_vec3i_add() {

    printf("### Testing vec3i sum...\n");

    vec3i a = {1, 2, 3};
    vec3i b = {2, 1, 1};
    vec3i c = vec3i_add(a, b);

    if (c.x != 3) return true;
    if (c.y != 3) return true;
    if (c.z != 4) return true;

    return false;
}

bool test_vec3i_sub() {

    printf("### Testing vec3i sub...\n");

    vec3i a = {1, 2, 4};
    vec3i b = {2, 1, 4};
    vec3i c = vec3i_sub(a, b);

    if (c.x != -1) return true;
    if (c.y !=  1) return true;
    if (c.z !=  0) return true;

    return false;
}

bool test_vec3i_mul() {

    printf("### Testing vec3i mul...\n");

    vec3i a = {1, 2, 3};
    int factor = 3;
    vec3i c = vec3i_mul(a, factor);

    if (c.x != 3) return true;
    if (c.y != 6) return true;
    if (c.z != 9) return true;

    return false;
}

bool test_vec3i_div() {

    printf("### Testing vec3i div...\n");

    vec3i a = {3, 6, 8};
    int factor = 3;
    vec3i c = vec3i_div(a, factor);

    if (c.x != 1) return true;
    if (c.y != 2) return true;
    if (c.z != 2) return true;

    return false;
}

bool test_vec3i_dot() {

    printf("### Testing vec3i dot...\n");

    vec3i a = {1, 2, 3};
    vec3i b = {3, 4, 5};

    int result = vec3i_dot(a, b);

    if (result != 26) return true;

    return false;
}

bool test_vec3i_len() {

    printf("### Testing vec3i len...\n");

    vec3i a = {1, 2, 2};

    int result = vec3i_len(a);

    if (result != 3) return true;

    return false;
}

bool test_vec3i_norm() {

    printf("### Testing vec3i norm...\n");

    vec3i a = {4, 3, 1};

    vec3i n = vec3i_norm(a);

    if (n.x != 4 / 5) return true;
    if (n.y != 3 / 5) return true;
    if (n.z != 1 / 5) return true;

    return false;
}

bool test_vec3i_cross() {

    printf("### Testing vec3i cross...\n");

    vec3i a = {1, 2, 3};
    vec3i b = {3, 4, 5};

    vec3i c = vec3i_cross(a, b);

    if (c.x != -2) return true;
    if (c.y !=  4) return true;
    if (c.z != -2) return true;

    return false;
}

int main(void) {
    printf("\n");

    TEST(test_vec3i_add);
    TEST(test_vec3i_sub);
    TEST(test_vec3i_mul);
    TEST(test_vec3i_div);
    TEST(test_vec3i_dot);
    TEST(test_vec3i_len);
    TEST(test_vec3i_norm);
    TEST(test_vec3i_cross);

    printf("\nAll tests passed. Bye!\n\n");

    return 0;
}
