// Given a smaller string s and a bigger string b, design an algorithm to find
// all permutations of the shorter string within the longer one. Print the
// location of each permutation.

#include <stdio.h>
#include <string.h>

int* findSubPermute(char* a, char* b, int* size);

int main()
{
    int s1;
    int* r1 = findSubPermute("abbc", "cbabadcbbabbcbabaabccbabc", &s1);

    return 0;
}

// Maintain a "char map" while iterating string b, each value indicates if the
// char in current substring is in excess (positive value) or in short (negative
// value) comparing with string a.
// 
// Use a diff value to check if all values in map are 0 at current index. When a
// value in map becomes 0, diff value minus 1, otherwise plus 1. If diff = 0,
// then current index is the starting position of a substring permutation.
// 
// E.g., string a = abc, string b = abdbca
// idx = 0, substring = "abd", map = { a = 0,  b = 0, c = -1, d = 1 }, diff = 2
// idx = 1, substring = "bdb", map = { a = -1, b = 1, c = -1, d = 1 }, diff = 4
// idx = 2, substring = "dbc", map = { a = -1, b = 0, c = 0,  d = 1 }, diff = 2
// idx = 3, substring = "bca", map = { a = 0,  b = 0, c = 0,  d = 0 }, diff = 0

int* findSubPermute(char* a, char* b, int* size)
{
    int map[26];
    int i, j;

    memset(map, 0, sizeof(map)); // Init to all 0

    // Init char map (map when index = 0 as above example)
    for (i = j = 0; char[i] != '\0' && char[j] != '\0'; i++, j++) {

    }
}