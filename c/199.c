// Given two strings, check if they are one (or zero) edit away, e.g.:
// ple,   pale -> true (add one)
// pales, pale -> true (remove one)
// pale,  bale -> true (replace one)
// pale,  bae  -> false

#include <stdio.h>
#include <string.h>

int isOneEdit(char* a, char* b);

int main()
{
    printf("%d\n", isOneEdit("ple", "pale"));
    printf("%d\n", isOneEdit("pales", "pale"));
    printf("%d\n", isOneEdit("pale", "bale"));
    printf("%d\n", isOneEdit("pale", "bae"));

    return 0;
}

int isOneEdit(char* a, char* b)
{
    int letters[128];
    int diff; // If there is already a diff
    int i, j;

    // Init all as 0
    memset(letters, 0, sizeof(letters));

    for (diff = i = j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++) {
        if (a[i] != b[j]) {
            if (diff)
                return 0; // There is already a diff
            diff = 1;

            if (a[i] == b[j + 1])
                j += 1; // Add one
            else if (a[i + 1] == b[j])
                i += 1; // Remove one
            else
                i += 1, j += 1; // Replace one
        }
    }

    // If both ended, or either one has only one letter left
    return (a[i] == b[j] || a[i + 1] == '\0' || b[j + 1] == '\0');
}