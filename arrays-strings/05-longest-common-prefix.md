# 14. Longest Common Prefix

**Difficulty:** Easy  
**Topic:** Arrays & Strings  
**LeetCode:** https://leetcode.com/problems/longest-common-prefix/

## Problem Description

Given an array of strings `strs`, return the longest string that starts every string in the array.

If no characters are shared at the beginning, return an empty string.

## Example

```text
Input:
strs = ["flower","flow","flight"]

Output:
"fl"
```

## Algorithm and Approach

The program starts with the first string as a candidate named `prefix`.

1. Copy `strs[0]` into `prefix`.
2. For every later string, compare characters at the beginning.
3. Use `j` to count matching characters.
4. Set `prefix[j]` to `'\0'` to shorten `prefix`.
5. Repeat until all strings have been checked.

## Step-by-Step Explanation

The `while` loop continues while:

- `prefix[j]` is not the end of the prefix.
- `strs[i][j]` is not the end of the current string.
- Both characters are equal.

At the first mismatch, `j` becomes the length of the remaining common prefix. Assigning `'\0'` to `prefix[j]` removes every character after that position.

For `["flower","flow","flight"]`:

- Comparing with `"flow"` changes `"flower"` to `"flow"`.
- Comparing with `"flight"` changes `"flow"` to `"fl"`.

## Explanation of the C Program

The function `longestCommonPrefix(char** strs, int strsSize)` uses:

- `prefix`, a dynamically allocated copy of the first string.
- `i` to scan the remaining strings.
- `j` to count matching starting characters.

If `strsSize == 0`, it allocates a one-character string and stores `'\0'`. If allocating `prefix` fails, it returns `NULL`. Each returned prefix must be freed by the caller.

The `LOCAL_TEST` block contains `runTest()` and `main()`. `runTest()` frees the returned `actual` string and returns `1` for a failing test.

## Time Complexity

`O(n * m)` in the worst case, where `n` is `strsSize` and `m` is the length of the first string.

## Space Complexity

`O(m)`, because `prefix` copies the first string of length `m`.

## Important Edge Cases

- An empty array should return an empty string.
- One string means that string is the prefix.
- A mismatch at the first character should return `""`.
- Allocation failure returns `NULL`.
- The caller must free the returned string.

## GCC Compilation Command

Run from the `arrays-strings` folder:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic -DLOCAL_TEST 05-longest-common-prefix.c -o longest-common-prefix.exe
```

## Local Execution Command

```powershell
.\longest-common-prefix.exe
```

## LeetCode Submission

Copy the complete contents of [05-longest-common-prefix.c](./05-longest-common-prefix.c) into LeetCode. The code under `#ifdef LOCAL_TEST` is excluded by LeetCode.
