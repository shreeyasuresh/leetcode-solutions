# 121. Best Time to Buy and Sell Stock

**Difficulty:** Easy  
**Topic:** Arrays & Strings  
**LeetCode:** https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

## Problem Description

You are given an array `prices`, where `prices[i]` is the stock price on day `i`.

Choose one day to buy and a later day to sell. Return the greatest possible profit. If no profit is possible, return `0`.

## Example

```text
Input:
prices = [7,1,5,3,6,4]

Output:
5
```

The stock can be bought at `1` and sold at `6`.

## Algorithm and Approach

The C program scans the prices once and tracks:

- `minimumPrice`: the lowest price seen so far.
- `maximumProfit`: the greatest profit found so far.
- `profit`: the current price minus `minimumPrice`.

For every price:

1. Update `minimumPrice` if the current price is smaller.
2. Otherwise, calculate `profit`.
3. Update `maximumProfit` if `profit` is larger.

## Step-by-Step Explanation

`minimumPrice` starts at `INT_MAX`, and `maximumProfit` starts at `0`.

When `prices[i] < minimumPrice`, the current price becomes the new possible buying price. When it is not lower, the program can calculate a selling profit.

This logic works because a stock can only be sold on or after the buying day. It does not need to remember every pair of prices.

## Explanation of the C Program

The function `maxProfit(int* prices, int pricesSize)` uses `i` to scan the array.

- The `if` branch updates `minimumPrice`.
- The `else` branch calculates `profit`.
- If `profit > maximumProfit`, `maximumProfit` receives the new value.

The `LOCAL_TEST` block contains `runTest()` and `main()`. It tests a normal sequence, decreasing prices, and a one-price array.

## Time Complexity

`O(n)`, where `n` is `pricesSize`.

## Space Complexity

`O(1)`, because only fixed variables are used.

## Important Edge Cases

- A one-price array returns `0`.
- A continuously decreasing array returns `0`.
- A lower price found after a previous sale becomes a new buying candidate.
- The profit should never be negative.

## GCC Compilation Command

Run from the `arrays-strings` folder:

```powershell
gcc -std=c11 -Wall -Wextra -pedantic -DLOCAL_TEST 04best-time-to-buy-and-sell-stock.c -o buy-sell-stock.exe
```

## Local Execution Command

```powershell
.\buy-sell-stock.exe
```

## LeetCode Submission

Copy the complete contents of [04best-time-to-buy-and-sell-stock.c](./04best-time-to-buy-and-sell-stock.c) into LeetCode. The code under `#ifdef LOCAL_TEST` is excluded by LeetCode.
