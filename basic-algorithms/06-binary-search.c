#include <stddef.h>

int search(int* nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (nums[middle] == target) {
            return middle;
        }

        if (nums[middle] < target) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }
    }

    return -1;
}

#ifdef LOCAL_TEST
#include <stdio.h>

static int runTest(const char* name, int* nums, int numsSize,
                   int target, int expected)
{
    int actual = search(nums, numsSize, target);

    printf("%s\n", name);
    printf("Expected: %d\n", expected);
    printf("Actual:   %d\n", actual);
    printf("Result: %s\n\n", actual == expected ? "PASS" : "FAIL");

    return actual == expected ? 0 : 1;
}

int main(void)
{
    int normal[] = {-1, 0, 3, 5, 9, 12};
    int negative[] = {-5, -2, 0, 4};
    int edge[] = {5};
    int failures = 0;

    failures += runTest("Normal: target 9",
                        normal, 6, 9, 4);
    failures += runTest("Edge: target missing",
                        normal, 6, 2, -1);
    failures += runTest("Edge: negative and single values",
                        negative, 4, -2, 1);
    failures += runTest("Edge: one-element array found",
                        edge, 1, 5, 0);

    return failures == 0 ? 0 : 1;
}
#endif
