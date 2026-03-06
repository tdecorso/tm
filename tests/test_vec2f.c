#include <stdio.h>
#include <stdbool.h>

#include "tm.h"

#define TEST(fun) \
    do { \
        if ((fun)()) { printf("### Test failed.\n"); return 1; } \
    } while (0);

bool test_vec2f_add() {

    printf("### Testing vec2f add...\n");

    vec2f a = {1.1, 2.1};
    vec2f b = {2.2, 1.2};
    vec2f c = vec2f_add(a, b);

    if ((c.x - 3.3) > 1e-6) return true;
    if ((c.y - 3.3) > 1e-6) return true;

    return false;
}

bool test_vec2f_sub() {

    printf("### Testing vec2f sub...\n");

    vec2f a = {1, 2};
    vec2f b = {2, 1};
    vec2f c = vec2f_sub(a, b);

    if ((c.x + 1) > 1e-6) return true;
    if ((c.y - 1) > 1e-6) return true;

    return false;
}

bool test_vec2f_mul() {

    printf("### Testing vec2f mul...\n");

    vec2f a = {1, 2};
    float factor = 3.3;
    vec2f c = vec2f_mul(a, factor);

    if ((c.x - 3.3) > 1e-6) return true;
    if ((c.y - 6.6) > 1e-6) return true;

    return false;
}

bool test_vec2f_div() {

    printf("### Testing vec2f div...\n");

    vec2f a = {3, 6};
    int factor = 2;
    vec2f c = vec2f_div(a, factor);

    if ((c.x - 1.5) > 1e-6) return true;
    if ((c.y - 3  ) > 1e-6) return true;

    return false;
}

bool test_vec2f_dot() {

    printf("### Testing vec2f dot...\n");

    vec2f a = {2, 2};
    vec2f b = {2, 2};

    int result = vec2f_dot(a, b);

    if ((result - 8) > 1e-6) return true;

    return false;
}

bool test_vec2f_len() {

    printf("### Testing vec2f len...\n");

    vec2f a = {1, 2};

    int result = vec2f_len(a);

    if ((result - 2) > 1e-6) return true;

    return false;
}

bool test_vec2f_norm() {

    printf("### Testing vec2f norm...\n");

    vec2f a = {4, 3};

    vec2f n = vec2f_norm(a);

    if ((n.x - 4.0/5) > 1e-6) return true;
    if ((n.y - 3.0/5) > 1e-6) return true;

    return false;
}

bool test_vec2f_transform() {

    printf("### Testing vec2f transform...\n");

    mat3f m = mat3f_identity();

    vec2f t = {2,3};

    m = mat3f_translate(m, t);

    vec2f v = {1,1};

    vec2f r = vec2f_transform(m, v);

    if (r.x != 3) return true;
    if (r.y != 4) return true;

    return false;
}

int main(void) {
    printf("\n");

    TEST(test_vec2f_add);
    TEST(test_vec2f_sub);
    TEST(test_vec2f_mul);
    TEST(test_vec2f_div);
    TEST(test_vec2f_dot);
    TEST(test_vec2f_len);
    TEST(test_vec2f_norm);
    TEST(test_vec2f_transform);

    printf("\nAll tests passed. Bye!\n\n");

    return 0;
}
