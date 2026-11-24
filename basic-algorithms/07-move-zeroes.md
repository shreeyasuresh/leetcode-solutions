# 283. Move Zeroes

**Difficulty:** Easy  
**Topic:** Basic Algorithms  
**LeetCode:** https://leetcode.com/problems/move-zeroes/

## Problem Description

Move all zero values to the end of an integer array while preserving the relative order of every nonzero value.

The solution should modify the existing array in place.

## Example

```text
Input:
nums = [0,1,0,3,12]

Output:
[1,3,12,0,0]
```

## Algorithm and Approach

The C program uses `nonZeroPosition` as the next position that should receive a nonzero value.

1. Scan the array using `i`.
2. Copy every nonzero value to `nums[nonZeroPosition]`.
3. Increase `nonZeroPosition` after each copy.
4. Fill the remaining array positions with zero.

## Step-by-Step Explanation

For `[0,1,0,3,12]`:

- Zero is skipped.
- `1` is copied to index `0`.
- Zero is skipped.
- `3` is copied to index `1`.
- `12` is copied to index `2`.
- The remaining positions are filled with zeros.

The relative order of `1`, `3`, and `12` does not change.

## Explanation of the C Program

The function `moveZeroes(int* nums, int numsSize)` modifies `nums` directly and returns nothing.

- `nonZeroPosition` points to the next destination for a nonzero value.
- `i` scans every source position.
- The second `while` loop writes zeros from `nonZeroPosition` to `numsSize - 1`.

The `LOCAL_TEST` block defines `runTest()` and `main()`. `runTest()` compares every array position with an expected array and records PASS/FAIL.

## Time Complexity

`O(n)`, where `n` is `numsSize`.

## Space Complexity

`O(1)`, because no extra array is created.

## Important Edge Cases

- An all-zero array remains all zeros.
- An array with no zeros remains unchanged.
- An empty array performs no operations.
- A nonzero value may keep the same index or move left.

## GCC Compilation Command

Run from the `basic-algorithms` folder:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic -DLOCAL_TEST 07-move-zeroes.c -o move-zeroes.exe
```

## Local Execution Command

```powershell
.\move-zeroes.exe
```

## LeetCode Submission

Copy the complete contents of [07-move-zeroes.c](./07-move-zeroes.c) into LeetCode. The code inside `#ifdef LOCAL_TEST` is excluded by LeetCode.
