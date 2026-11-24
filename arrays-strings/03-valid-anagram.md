# 242. Valid Anagram

**Difficulty:** Easy  
**Topic:** Arrays & Strings  
**LeetCode:** https://leetcode.com/problems/valid-anagram/

## Problem Description

Two strings are anagrams if they contain exactly the same lowercase letters, with the same number of copies of each letter.

Given strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

## Example

```text
Input:
s = "anagram"
t = "nagaram"

Output:
true
```

Another example:

```text
s = "rat"
t = "car"
Output: false
```

## Algorithm and Approach

The C program uses an integer array named `frequency` with 26 positions, one for every lowercase English letter.

1. Add `1` to the counter for every character in `s`.
2. Subtract `1` from the counter for every character in `t`.
3. Check all 26 counters.
4. Return `true` only when every counter is `0`.

## Step-by-Step Explanation

The expression `s[i] - 'a'` converts a lowercase letter to an array index:

- `'a'` becomes `0`.
- `'b'` becomes `1`.
- `'z'` becomes `25`.

For `s = "anagram"` and `t = "nagaram"`, both strings have the same letters. Counting `s` and subtracting `t` therefore leaves every value in `frequency` as `0`.

The final loop checks `frequency[i]` for `i` from `0` to `25`. A nonzero value means one string has extra or missing occurrences of that letter.

## Explanation of the C Program

The function `isAnagram(char* s, char* t)` uses:

- `frequency[26]` to store letter counts.
- `i` to scan both strings and later scan the frequency array.

The first loop increments counters for `s`. The second loop decrements counters for `t`. The final loop returns `false` for any nonzero counter.

The code under `#ifdef LOCAL_TEST` contains `runTest()` and `main()`. It prints the expected result, actual result, and PASS/FAIL status for the normal, empty-string, and mismatched test cases.

## Time Complexity

`O(n)`, where `n` is the total number of characters scanned in `s` and `t`. The final 26-position check takes constant time.

## Space Complexity

`O(1)`, because `frequency` always has exactly 26 integer positions.

## Important Edge Cases

- Two empty strings are valid anagrams.
- Strings with different lengths should return `false`.
- Repeated letters must have exactly the same counts.
- Lowercase English letters are assumed, matching the problem constraints.

## GCC Compilation Command

Run from the `arrays-strings` folder:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic -DLOCAL_TEST 03-valid-anagram.c -o valid-anagram.exe
```

## Local Execution Command

```powershell
.\valid-anagram.exe
```

## LeetCode Submission

Copy the complete contents of [03-valid-anagram.c](./03-valid-anagram.c) into LeetCode. The local test code inside `#ifdef LOCAL_TEST` is automatically excluded because `LOCAL_TEST` is not defined by LeetCode.
