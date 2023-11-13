#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int longestPalindromicSubstring(char *str)
{
    int n = strlen(str);
    int dp[n][n];      // 2D array to store results of subproblems
    int maxLength = 1; // All substrings of length 1 are palindromes by default

    // Initialize the dp array for single characters
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
    }

    // Check for substrings of length 2
    int start = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            dp[i][i + 1] = 1;
            start = i;
            maxLength = 2;
        }
    }

    // Check for substrings of length 3 or more
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1; // Ending index of current substring

            // Check if the substring is palindrome
            if (dp[i + 1][j - 1] && str[i] == str[j])
            {
                dp[i][j] = 1;

                // Update the maximum length and starting index of the longest palindromic substring found so far
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }

    // Print the longest palindromic substring
    printf("Longest Palindromic Substring: ");
    for (int i = start; i < start + maxLength; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");

    return maxLength;
}

int main()
{
    char str[] = "babad";
    int length = longestPalindromicSubstring(str);

    printf("Length of the Longest Palindromic Substring: %d\n", length);

    return 0;
}
