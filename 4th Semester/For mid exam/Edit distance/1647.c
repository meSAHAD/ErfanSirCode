#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1001
#define BASE 10

int memo[MAX_N][3000]; 

void initialize()
{
    memo[1][0] = 0;
    int plus = 1;
    for (int i = 2; i <= MAX_N; i++)
    {
        int carry = 0;
        int len = 1;
        for (int j = 0; j < len; j++)
        {
            int val = memo[i - 1][j] * 2 + carry;
            memo[i][j] = val % BASE;
            carry = val / BASE;
        }
        if (plus)
        {
            memo[i][0]++;
            plus = 0;
        }
        else
        {
            memo[i][0]--;
            plus = 1;
        }
        while (carry > 0)
        {
            memo[i][len++] = carry % BASE;
            carry /= BASE;
        }
        memo[i][len] = -1; // Mark the end of the number
    }
}

void printNumber(int *num)
{
    int len = 0;
    while (num[len] != -1)
    {
        len++;
    }
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%d", num[i]);
    }
}

int main()
{
    initialize();
    int n;
    while (scanf("%d", &n) == 1)
    {
        printNumber(memo[n]);
        printf("\n");
    }
    return 0;
}
