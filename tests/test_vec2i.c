#include <stdio.h>
#include <stdbool.h>

#include "tm.h"

#define TEST(fun) \
    do { \
        if ((fun)()) { printf("### Test failed.\n"); return 1; } \
    } while (0);

bool test_vec2i_add() {

    printf("### Testing vec2i sum...\n");

    vec2i a = {1, 2};
    vec2i b = {2, 1};
    vec2i c = vec2i_add(a, b);

    if (c.x != 3) return true;
    if (c.y != 3) return true;

    return false;
}

bool test_vec2i_sub() {

    printf("### Testing vec2i sub...\n");

    vec2i a = {1, 2};
    vec2i b = {2, 1};
    vec2i c = vec2i_sub(a, b);

    if (c.x != -1) return true;
    if (c.y != 1) return true;

    return false;
}

bool test_vec2i_mul() {

    printf("### Testing vec2i mul...\n");

    vec2i a = {1, 2};
    int factor = 3;
    vec2i c = vec2i_mul(a, factor);

    if (c.x != 3) return true;
    if (c.y != 6) return true;

    return false;
}

bool test_vec2i_div() {

    printf("### Testing vec2i div...\n");

    vec2i a = {3, 6};
    int factor = 3;
    vec2i c = vec2i_div(a, factor);

    if (c.x != 1) return true;
    if (c.y != 2) return true;

    return false;
}

bool test_vec2i_dot() {

    printf("### Testing vec2i dot...\n");

    vec2i a = {2, 2};
    vec2i b = {2, 2};

    int result = vec2i_dot(a, b);

    if (result != 8) return true;

    return false;
}

bool test_vec2i_len() {

    printf("### Testing vec2i len...\n");

    vec2i a = {1, 2};

    int result = vec2i_len(a);

    if (result != 2) return true;

    return false;
}

bool test_vec2i_norm() {

    printf("### Testing vec2i norm...\n");

    vec2i a = {4, 3};

    vec2i n = vec2i_norm(a);

    if (n.x != 4 / 5) return true;
    if (n.y != 3 / 5) return true;

    return false;
}

int main(void) {
    printf("\n");

    TEST(test_vec2i_add);
    TEST(test_vec2i_sub);
    TEST(test_vec2i_mul);
    TEST(test_vec2i_div);
    TEST(test_vec2i_dot);
    TEST(test_vec2i_len);
    TEST(test_vec2i_norm);

    printf("\nAll tests passed. Bye!\n\n");

    return 0;
}
