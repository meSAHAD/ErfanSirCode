#include <stdio.h>
#include <string.h>

int min(int a, int b, int c)
{
    if (a < b && a < c)
        return a;
    if (b < c)
        return b;
    return c;
}

int editDistance(char *str1, char *str2)
{
    int m = strlen(str1);
    int n = strlen(str2);
    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0)
                dp[i][j] = j; // Insertion
            else if (j == 0)
                dp[i][j] = i; // Deletion
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1]; // No operation needed
            else
                dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]); // Insert, Delete, Replace
        }
    }

    return dp[m][n];
}

int main()
{
    char str1[] = "kitten";
    char str2[] = "sitting";

    int distance = editDistance(str1, str2);

    printf("Edit Distance between '%s' and '%s' is %d\n", str1, str2, distance);

    return 0;
}
