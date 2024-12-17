#include <stdio.h>
#include <string.h>

void naiveSearch(char *text, char *pattern)
{
    int n = strlen(text);
    int m = strlen(pattern);

    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";

    naiveSearch(text, pattern);
    return 0;
}