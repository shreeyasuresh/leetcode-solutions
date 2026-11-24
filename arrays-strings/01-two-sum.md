# 1. Two Sum

**Difficulty:** Easy  
**Topic:** Arrays & Strings  
**LeetCode:** https://leetcode.com/problems/two-sum/

## Problem Summary

Given an array `nums` and a `target`, return the indices of the two numbers that add up to `target`.

- Each input has exactly one valid solution.
- The same array element cannot be used twice.
- The answer must use index order in ascending order.

## Example

```text
nums = [2,7,11,15]
target = 9
output = [0,1]
```

The values at indices `0` and `1` are `2` and `7`, and `2 + 7 = 9`.

## Logic

1. Start with the first index `i`.
2. Check every later index `j`.
3. If `nums[i] + nums[j]` equals `target`, allocate an array of two integers.
4. Store `i` and `j`, set `*returnSize = 2`, and return the array.

This nested-loop approach checks each pair only once.

## C Solution

See [01-two-sum.c](./01-two-sum.c).

## Local Test Cases

| Case | nums | target | Expected |
|---|---|---:|---|
| Normal | `[2,7,11,15]` | 9 | `[0,1]` |
| Edge | `[3,3]` | 6 | `[0,1]` |

Compile and run:

```powershell
gcc -DLOCAL_TEST -std=c11 -Wall -Wextra -pedantic 01-two-sum.c -o 01-two-sum.exe
.\01-two-sum.exe
```

Run this command from the `arrays-strings` folder.

## Complexity

- **Time:** `O(n²)` because each pair may need to be checked.
- **Space:** `O(1)` for the algorithm. The returned answer requires `O(2)` space, which is constant.
