// String compression: For example, "aabcccccaaa" would become "a2blc5a3". If
// the compressed string would not become smaller than the original string,
// return the original string.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* compress(char* str);
int getRepeat(char* str);

int main()
{
    printf("%s\n", compress("abcd"));
    printf("%s\n", compress("aaabbbcccddd"));
    printf("%s\n", compress("aabbcc"));
    printf("%s\n", compress("aaabccc"));

    return 0;
}

char* compress(char* str)
{
    int l = (int)strlen(str);
    char* new = malloc(sizeof(char) * (l + 1));
    int i, j, count;

    for (i = j = 0; i < l && j < l;) {
        new[j++] = str[i];          // Write current letter
        count = getRepeat(str + i); // Get repeated time of current letter
        i += count;                 // Move to next different letter
        while (count > 0 && j < l) {
            new[j++] = '0' + count % 10; // Write repeat time of current letter
            count /= 10;                 // TODO: Revert the number, currently backwards
        }
    }

    if (i <= j) {
        free(new);
        return str;
    } else {
        new[j] = '\0';
        return new;
    }
}

// Get repeated time of the first letter
// e.g. "aaabc" => 3, "a" => 1
int getRepeat(char* str)
{
    int i;
    for (i = 1; str[i] == str[i - 1]; i++)
        ;
    return i;
}