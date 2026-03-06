#include <stdio.h>
#include <stdbool.h>

#include "tm.h"

#define TEST(fun) \
    do { \
        if ((fun)()) { printf("### Test failed.\n"); return 1; } \
    } while (0);


bool test_mat3i_identity() {

    printf("### Testing mat3i identity...\n");

    mat3i m = mat3i_identity();

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int expected = i == j ? 1 : 0;
            if (m.data[i * 3 + j] != expected) return true;
        }
    }

    return false;
}

bool test_mat3i_add() {

    printf("### Testing mat3i add...\n");

    mat3i a = {{1, 2, 3, 3, 2, 1, 1, 2, 3}};
    mat3i b = {{4, 5, 6, 6, 5, 4, 4, 6, 5}};

    mat3i m = mat3i_add(a, b);

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

bool test_mat3i_sub() {

    printf("### Testing mat3i sub...\n");

    mat3i a = {{1, 2, 3, 3, 2, 1, 1, 2, 3}};
    mat3i b = {{4, 5, 6, 6, 5, 4, 4, 6, 5}};

    mat3i m = mat3i_sub(a, b);

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

int main(void) {
    printf("\n");

    TEST(test_mat3i_identity);
    TEST(test_mat3i_add);
    TEST(test_mat3i_sub);

    printf("\nAll tests passed. Bye!\n\n");

    return 0;
}
