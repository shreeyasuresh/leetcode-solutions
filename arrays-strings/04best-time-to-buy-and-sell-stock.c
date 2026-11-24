#include <limits.h>

int maxProfit(int* prices, int pricesSize)
{
    int minimumPrice = INT_MAX;
    int maximumProfit = 0;
    int i;

    for (i = 0; i < pricesSize; i++) {
        if (prices[i] < minimumPrice) {
            minimumPrice = prices[i];
        } else {
            int profit = prices[i] - minimumPrice;
            if (profit > maximumProfit) {
                maximumProfit = profit;
            }
        }
    }

    return maximumProfit;
}

#ifdef LOCAL_TEST
#include <stdio.h>

static int runTest(const char* name, int* prices, int pricesSize,
                   int expected)
{
    int actual = maxProfit(prices, pricesSize);

    printf("%s\n", name);
    printf("Expected: %d\n", expected);
    printf("Actual:   %d\n", actual);
    printf("Result: %s\n\n", actual == expected ? "PASS" : "FAIL");

    return actual == expected ? 0 : 1;
}

int main(void)
{
    int normal[] = {7, 1, 5, 3, 6, 4};
    int decreasing[] = {7, 6, 4, 3, 1};
    int edge[] = {1};
    int failures = 0;

    failures += runTest("Normal: [7,1,5,3,6,4]",
                        normal, 6, 5);
    failures += runTest("Edge: decreasing prices",
                        decreasing, 5, 0);
    failures += runTest("Edge: one price",
                        edge, 1, 0);

    return failures == 0 ? 0 : 1;
}
#endif
