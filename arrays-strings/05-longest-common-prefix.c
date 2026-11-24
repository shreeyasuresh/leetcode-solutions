#include <stdlib.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize)
{
    int i;
    int j;
    char* prefix;

    if (strsSize == 0) {
        char* empty = (char*)malloc(1);
        if (empty != NULL) {
            empty[0] = '\0';
        }
        return empty;
    }

    prefix = (char*)malloc(strlen(strs[0]) + 1);
    if (prefix == NULL) {
        return NULL;
    }

    strcpy(prefix, strs[0]);

    for (i = 1; i < strsSize; i++) {
        j = 0;
        while (prefix[j] != '\0' &&
               strs[i][j] != '\0' &&
               prefix[j] == strs[i][j]) {
            j++;
        }
        prefix[j] = '\0';
    }

    return prefix;
}

#ifdef LOCAL_TEST
#include <stdio.h>

static int runTest(const char* name, char** strs, int strsSize,
                   const char* expected)
{
    char* actual = longestCommonPrefix(strs, strsSize);
    int passed = actual != NULL && strcmp(actual, expected) == 0;

    printf("%s\n", name);
    printf("Expected: \"%s\"\n", expected);
    printf("Actual:   \"%s\"\n", actual == NULL ? "" : actual);
    printf("Result: %s\n\n",
           passed ? "PASS" : "FAIL");

    free(actual);
    return passed ? 0 : 1;
}

int main(void)
{
    char* normal[] = {"flower", "flow", "flight"};
    char* noPrefix[] = {"dog", "racecar", "car"};
    char* edge[] = {"single"};
    int failures = 0;

    failures += runTest("Normal: flower/flow/flight",
                        normal, 3, "fl");
    failures += runTest("Edge: no common prefix",
                        noPrefix, 3, "");
    failures += runTest("Edge: only one string",
                        edge, 1, "single");

    return failures == 0 ? 0 : 1;
}
#endif
