#include <stdbool.h>

bool isAnagram(char* s, char* t)
{
    int frequency[26] = {0};
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        frequency[s[i] - 'a']++;
    }

    for (i = 0; t[i] != '\0'; i++) {
        frequency[t[i] - 'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (frequency[i] != 0) {
            return false;
        }
    }

    return true;
}

#ifdef LOCAL_TEST
#include <stdio.h>
#include <string.h>

static int runTest(const char* name, char* s, char* t, bool expected)
{
    bool actual = isAnagram(s, t);

    printf("%s\n", name);
    printf("Expected: %s\n", expected ? "true" : "false");
    printf("Actual:   %s\n", actual ? "true" : "false");
    printf("Result: %s\n\n", actual == expected ? "PASS" : "FAIL");

    return actual == expected ? 0 : 1;
}

int main(void)
{
    int failures = 0;

    failures += runTest("Normal: anagram/nagaram",
                        "anagram", "nagaram", true);
    failures += runTest("Edge: empty strings",
                        "", "", true);
    failures += runTest("Mismatch: rat/car",
                        "rat", "car", false);

    return failures == 0 ? 0 : 1;
}
#endif
