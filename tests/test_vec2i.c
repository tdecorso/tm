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

int main(void) {
    printf("\n");

    TEST(test_vec2i_add);
    TEST(test_vec2i_sub);

    printf("\nAll tests passed. Bye!\n\n");

    return 0;
}
