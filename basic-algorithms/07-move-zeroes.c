void moveZeroes(int* nums, int numsSize)
{
    int nonZeroPosition = 0;
    int i;

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[nonZeroPosition] = nums[i];
            nonZeroPosition++;
        }
    }

    while (nonZeroPosition < numsSize) {
        nums[nonZeroPosition] = 0;
        nonZeroPosition++;
    }
}

#ifdef LOCAL_TEST
#include <stdio.h>

static int runTest(const char* name, int* nums, int numsSize,
                   const int* expected)
{
    int i;
    int passed = 1;

    moveZeroes(nums, numsSize);

    printf("%s\n", name);
    printf("Expected: [");
    for (i = 0; i < numsSize; i++) {
        printf("%d%s", expected[i], i + 1 < numsSize ? "," : "");
    }
    printf("]\n");

    printf("Actual:   [");
    for (i = 0; i < numsSize; i++) {
        printf("%d%s", nums[i], i + 1 < numsSize ? "," : "");
    }
    printf("]\n");

    for (i = 0; i < numsSize; i++) {
        if (nums[i] != expected[i]) {
            passed = 0;
        }
    }

    printf("Result: %s\n\n", passed ? "PASS" : "FAIL");
    return passed ? 0 : 1;
}

int main(void)
{
    int normal[] = {0, 1, 0, 3, 12};
    int edgeZeros[] = {0, 0, 0};
    int edgeNoZeros[] = {1, 2, 3};
    const int normalExpected[] = {1, 3, 12, 0, 0};
    const int zeroExpected[] = {0, 0, 0};
    const int noZeroExpected[] = {1, 2, 3};
    int failures = 0;

    failures += runTest("Normal: [0,1,0,3,12]",
                        normal, 5, normalExpected);
    failures += runTest("Edge: all zeros",
                        edgeZeros, 3, zeroExpected);
    failures += runTest("Edge: no zeros",
                        edgeNoZeros, 3, noZeroExpected);

    return failures == 0 ? 0 : 1;
}
#endif
