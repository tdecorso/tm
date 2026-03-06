#include <stdio.h>
#include <stdbool.h>

#include "tm.h"

#define TEST(fun) \
    do { \
        if ((fun)()) { printf("### Test failed.\n"); return 1; } \
    } while (0);

bool test_vec3f_add() {

    printf("### Testing vec3f add...\n");

    vec3f a = {1.1, 2.1, 3.2};
    vec3f b = {2.2, 1.2, 2.4};
    vec3f c = vec3f_add(a, b);

    if ((c.x - 3.3) > 1e-6) return true;
    if ((c.y - 3.3) > 1e-6) return true;
    if ((c.z - 5.6) > 1e-6) return true;

    return false;
}

bool test_vec3f_sub() {

    printf("### Testing vec3f sub...\n");

    vec3f a = {1, 2, 2};
    vec3f b = {2, 1, 2};
    vec3f c = vec3f_sub(a, b);

    if ((c.x + 1) > 1e-6) return true;
    if ((c.y - 1) > 1e-6) return true;
    if ((c.z) > 1e-6) return true;

    return false;
}

bool test_vec3f_mul() {

    printf("### Testing vec3f mul...\n");

    vec3f a = {1, 2, 3};
    float factor = 3.3;
    vec3f c = vec3f_mul(a, factor);

    if ((c.x - 3.3) > 1e-6) return true;
    if ((c.y - 6.6) > 1e-6) return true;
    if ((c.z - 9.9) > 1e-6) return true;

    return false;
}

bool test_vec3f_div() {

    printf("### Testing vec3f div...\n");

    vec3f a = {3, 6, 2};
    int factor = 2;
    vec3f c = vec3f_div(a, factor);

    if ((c.x - 1.5) > 1e-6) return true;
    if ((c.y - 3  ) > 1e-6) return true;
    if ((c.z - 1  ) > 1e-6) return true;

    return false;
}

bool test_vec3f_dot() {

    printf("### Testing vec3f dot...\n");

    vec3f a = {1, 2.2, 3};
    vec3f b = {3, 4, 5.1};

    float result = vec3f_dot(a, b);

    if ((result - 27.1) > 1e-6) return true;

    return false;
}

bool test_vec3f_len() {

    printf("### Testing vec3f len...\n");

    vec3f a = {3, 2.5, -1};

    float result = vec3f_len(a);

    if ((result - 4.03113) > 1e-6) return true;

    return false;
}

bool test_vec3f_norm() {

    printf("### Testing vec3f norm...\n");

    vec3f a = {4, 3.3, 2};

    vec3f n = vec3f_norm(a);

    if ((n.x - 0.719699) > 1e-6) return true;
    if ((n.y - 0.593752) > 1e-6) return true;
    if ((n.z -  0.35985) > 1e-6) return true;


    return false;
}

bool test_vec3f_cross() {

    printf("### Testing vec3f cross...\n");

    vec3f a = {1, 2, 3};
    vec3f b = {3, 4.2, 5};

    vec3f c = vec3f_cross(a, b);

    if ((c.x + 2.6) > 1e-6) return true;
    if ((c.y - 4  ) > 1e-6) return true;
    if ((c.z + 1.8) > 1e-6) return true;

    return false;
}

int main(void) {
    printf("\n");

    TEST(test_vec3f_add);
    TEST(test_vec3f_sub);
    TEST(test_vec3f_mul);
    TEST(test_vec3f_div);
    TEST(test_vec3f_dot);
    TEST(test_vec3f_len);
    TEST(test_vec3f_norm);
    TEST(test_vec3f_cross);

    printf("\nAll tests passed. Bye!\n\n");

    return 0;
}
