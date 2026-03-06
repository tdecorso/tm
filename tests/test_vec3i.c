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

int main(void) {
    printf("\n");

    TEST(test_vec3i_add);
    TEST(test_vec3i_sub);

    printf("\nAll tests passed. Bye!\n\n");

    return 0;
}
