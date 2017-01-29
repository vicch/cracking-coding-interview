#include <stdio.h>
#include <string.h>

int isUnique(char* str);

int main()
{
    printf("%d\n", isUnique("abcdefga"));

    return 0;
}

int isUnique(char* str)
{
    int chars[128], i;

    // Init all as 0
    memset(chars, 0, sizeof(chars));

    for (i = 0; str[i] != '\0'; i++)
    {
        if (i >= 128 || chars[str[i]]) {
            return 0;
        }
        chars[str[i]] = 1;
    }

    return 1;
}