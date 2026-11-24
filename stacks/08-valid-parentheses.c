#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* s)
{
    int length = 0;
    int top = 0;
    char* stack;
    int i;

    while (s[length] != '\0') {
        length++;
    }

    stack = (char*)malloc((size_t)length + 1);
    if (stack == NULL) {
        return false;
    }

    for (i = 0; i < length; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[top++] = s[i];
        } else {
            if (top == 0) {
                free(stack);
                return false;
            }

            if ((s[i] == ')' && stack[top - 1] != '(') ||
                (s[i] == '}' && stack[top - 1] != '{') ||
                (s[i] == ']' && stack[top - 1] != '[')) {
                free(stack);
                return false;
            }

            top--;
        }
    }

    {
        bool valid = top == 0;
        free(stack);
        return valid;
    }
}

#ifdef LOCAL_TEST
#include <stdio.h>

static int runTest(const char* name, char* s, bool expected)
{
    bool actual = isValid(s);

    printf("%s\n", name);
    printf("Expected: %s\n", expected ? "true" : "false");
    printf("Actual:   %s\n", actual ? "true" : "false");
    printf("Result: %s\n\n", actual == expected ? "PASS" : "FAIL");

    return actual == expected ? 0 : 1;
}

int main(void)
{
    int failures = 0;

    failures += runTest("Normal: ()[]{}",
                        "()[]{}", true);
    failures += runTest("Edge: mismatched",
                        "(]", false);
    failures += runTest("Edge: empty string",
                        "", true);

    return failures == 0 ? 0 : 1;
}
#endif
