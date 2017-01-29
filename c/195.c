// Check if a string is a permutation of a palindrome

#include <stdio.h>
#include <string.h>

int isPermutation(char* str);

int main()
{
    printf("%d\n", isPermutation("aabbcc"));
    printf("%d\n", isPermutation("aabbccd"));
    printf("%d\n", isPermutation("aabbccde"));

    return 0;
}

int isPermutation(char* str)
{
    int i;
    int odd; // Number of odd letters
    int letters[128];

    // Init all as 0
    memset(letters, 0, sizeof(letters));

    for (odd = i = 0; str[i] != '\0'; i++) {
        if (letters[str[i]]) {
            letters[str[i]] = 0;
            odd -= 1;
        } else {
            letters[str[i]] = 1;
            odd += 1;
        }
    }

    return odd <= 1;
}