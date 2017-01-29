// URLify: Replace all spaces in a string with "%20"

#include <stdio.h>
#include <stdlib.h>

char* urlify(char* str);

int main()
{
    printf("%s\n", urlify("A Sample String"));
    printf("%s\n", urlify("Another  Sample  String"));

    return 0;
}

char* urlify(char* str)
{
    int i, j;
    int s; // Number of spaces
    int l; // New string length

    // Get old string length and number of spaces
    for (i = s = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            s += 1; 
    }

    l = i + s * 2;

    // Init new string
    char* new = malloc(sizeof(char) * (l + 1));
    new[l] = '\0';

    // i: new string index
    // j: old string index
    for (j = i - 1, i = l - 1; j >= 0; j--, i--) {
        if (str[j] == ' ') {
            new[i]     = '0';
            new[i - 1] = '2';
            new[i - 2] = '%';
            i -= 2;
        } else
            new[i] = str[j];
    }

    return new;
}