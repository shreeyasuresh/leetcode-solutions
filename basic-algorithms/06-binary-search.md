# 704. Binary Search

**Difficulty:** Easy  
**Topic:** Basic Algorithms  
**LeetCode:** https://leetcode.com/problems/binary-search/

## Problem Description

Given a sorted integer array `nums` and an integer `target`, return the index of `target`.

Return `-1` if `target` is not present in the array.

## Example

```text
Input:
nums = [-1,0,3,5,9,12]
target = 9

Output:
4
```

If `target = 2`, the result is `-1`.

## Algorithm and Approach

Binary search repeatedly checks the middle element of the remaining sorted range.

1. Set `left` to `0`.
2. Set `right` to `numsSize - 1`.
3. Calculate `middle`.
4. Return `middle` if it equals `target`.
5. Search the right half if `nums[middle] < target`.
6. Search the left half if `nums[middle] > target`.

## Step-by-Step Explanation

The middle position is calculated as:

```c
middle = left + (right - left) / 2;
```

This is safer than `left + right` because it avoids large intermediate sums.

- If `nums[middle] == target`, the function returns `middle`.
- If `nums[middle] < target`, it sets `left = middle + 1`.
- Otherwise, it sets `right = middle - 1`.

The loop ends when `left > right`. The function then returns `-1`.

## Explanation of the C Program

The function `search(int* nums, int numsSize, int target)` uses:

- `left` for the first index in the current search range.
- `right` for the last index in the current search range.
- `middle` for the index currently being checked.

The `LOCAL_TEST` block prints the expected index, actual index, and PASS/FAIL result. It includes found, missing, negative-value, and one-element tests.

## Time Complexity

`O(log n)`, because the search range is divided in half on every iteration.

## Space Complexity

`O(1)`, because only `left`, `right`, and `middle` are used.

## Important Edge Cases

- An empty array gives `right = -1`, so `-1` is returned.
- A one-element array is found or not found directly.
- Negative values are handled normally.
- The target may be outside the array range.

## GCC Compilation Command

Run from the `basic-algorithms` folder:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic -DLOCAL_TEST 06-binary-search.c -o binary-search.exe
```

## Local Execution Command

```powershell
.\binary-search.exe
```

## LeetCode Submission

Copy the complete contents of [06-binary-search.c](./06-binary-search.c) into LeetCode. The code under `#ifdef LOCAL_TEST` is excluded because `LOCAL_TEST` is not defined by LeetCode.
