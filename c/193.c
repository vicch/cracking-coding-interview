// Check if one string is a permutation of another

#include <stdio.h>
#include <string.h>

int isPermutation(char* a, char* b);

int main()
{
    printf("%d\n", isPermutation("abcde", "cebad"));

    return 0;
}

int isPermutation(char* a, char* b)
{
    int letters[128];
    int i;

    // Init all as 0
    memset(letters, 0, sizeof(letters));

    for (i = 0; a[i] != '\0'; i++)
        letters[a[i]] += 1;

    for (i = 0; b[i] != '\0'; i++)
        letters[b[i]] -= 1;

    for (i = 0; i < 128; i++)
        if (letters[i] != 0)
            return 0;

    return 1;
}