# 20. Valid Parentheses

**Difficulty:** Easy  
**Topic:** Stacks  
**LeetCode:** https://leetcode.com/problems/valid-parentheses/

## Problem Description

Determine whether a string containing brackets is valid.

A valid string requires:

- Every opening bracket to have a matching closing bracket.
- Matching brackets to have the correct type.
- Closing brackets to appear in reverse opening order.

The valid pairs are `()`, `{}`, and `[]`.

## Example

```text
Input:
s = "()[]{}"

Output:
true
```

Another example:

```text
s = "(]"
Output: false
```

## Algorithm and Approach

The C program uses a dynamically allocated character array named `stack`.

1. Measure the string length.
2. Allocate `stack`.
3. Push every opening bracket.
4. For a closing bracket, compare it with `stack[top - 1]`.
5. Pop a matching opening bracket.
6. Return `true` only when `top` is `0` at the end.

## Step-by-Step Explanation

`top` counts the number of opening brackets currently in the stack.

- `(`, `{`, or `[` is pushed with `stack[top++] = s[i]`.
- A closing bracket requires `top > 0`.
- `)` must match a top value of `(`.
- `}` must match a top value of `{`.
- `]` must match a top value of `[`.

After a match, `top` is decreased. If the stack is empty at the end, every opening bracket was matched.

## Explanation of the C Program

The function `isValid(char* s)` uses:

- `length` to count characters.
- `stack` to store opening brackets.
- `top` as both the stack size and next insertion position.
- `i` to scan `s`.

It frees `stack` for mismatch cases and for the final return. If `malloc` fails, it returns `false`.

The `LOCAL_TEST` block uses `runTest()` and `main()` to test matching, mismatched, and empty strings.

## Time Complexity

`O(n)`, where `n` is the string length.

## Space Complexity

`O(n)` for the dynamically allocated stack.

## Important Edge Cases

- An empty string is valid.
- `"("` is invalid because an opening bracket remains.
- `")"` is invalid because the stack is empty.
- `"(]"` is invalid because the bracket types do not match.
- Allocation failure returns `false`.

## GCC Compilation Command

Run from the `stacks` folder:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic -DLOCAL_TEST 08-valid-parentheses.c -o valid-parentheses.exe
```

## Local Execution Command

```powershell
.\valid-parentheses.exe
```

## LeetCode Submission

Copy the complete contents of [08-valid-parentheses.c](./08-valid-parentheses.c) into LeetCode. The code under `#ifdef LOCAL_TEST` is excluded because `LOCAL_TEST` is not defined by LeetCode.
