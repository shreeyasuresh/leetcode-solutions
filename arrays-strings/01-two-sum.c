#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i;
    int j;

    *returnSize = 2;

    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                int* answer = (int*)malloc(2 * sizeof(int));

                answer[0] = i;
                answer[1] = j;
                return answer;
            }
        }
    }

    *returnSize = 0;
    return NULL;
}

#ifdef LOCAL_TEST
static void runTest(const char* name, int* nums, int numsSize,
                    int target, const int expected[2])
{
    int returnSize = 0;
    int* actual = twoSum(nums, numsSize, target, &returnSize);
    int passed = 0;

    printf("%s\n", name);
    printf("Expected: [%d,%d]\n", expected[0], expected[1]);
    printf("Actual:   ");

    if (actual != NULL && returnSize == 2) {
        printf("[%d,%d]\n", actual[0], actual[1]);
        passed = (actual[0] == expected[0] &&
                  actual[1] == expected[1]);
    } else {
        printf("NULL\n");
    }

    printf("Result: %s\n\n", passed ? "PASS" : "FAIL");
    free(actual);
}

int main(void)
{
    int normalNums[] = {2, 7, 11, 15};
    int edgeNums[] = {3, 3};
    const int normalExpected[] = {0, 1};
    const int edgeExpected[] = {0, 1};

    runTest("Normal: nums=[2,7,11,15], target=9",
            normalNums, 4, 9, normalExpected);
    runTest("Edge: nums=[3,3], target=6",
            edgeNums, 2, 6, edgeExpected);

    return 0;
}
#endif