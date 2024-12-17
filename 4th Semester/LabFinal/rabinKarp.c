#include <stdio.h>
#include <string.h>

#define d 256 // Number of characters in the input alphabet (e.g., ASCII)
#define q 101 // A prime number to reduce the hash value

// Rabin-Karp Algorithm for Pattern Matching
void rabinKarp(char *text, char *pattern)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int patternHash = 0;
    int textHash = 0;
    int h = 1;

    // Calculate h = pow(d, M-1) % q
    for (i = 0; i < M - 1; i++)
    {
        h = (h * d) % q;
    }

    // Calculate the hash values of the pattern and the first window of text
    for (i = 0; i < M; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % q;
        textHash = (d * textHash + text[i]) % q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {
        // Check if the hash values of the current window and the pattern match
        if (patternHash == textHash)
        {
            // If hash matches, check for character by character match
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }

            // If we find a match, print the result
            if (j == M)
            {
                printf("Pattern found at index %d\n", i);
            }
        }

        // Calculate hash for the next window of text (slide the window)
        if (i < N - M)
        {
            textHash = (d * (textHash - text[i] * h) + text[i + M]) % q;

            // If textHash becomes negative, then convert it to positive
            if (textHash < 0)
            {
                textHash = (textHash + q);
            }
        }
    }
}

int main()
{
    char text[] = "ABRAKADABRA";
    char pattern[] = "ABRA";

    rabinKarp(text, pattern);

    return 0;
}
