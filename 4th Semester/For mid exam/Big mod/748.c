#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS 10000

void powerToPlainString(char *numStr, int pow, char *result)
{
    int numLen = strlen(numStr);
    int num[MAX_DIGITS] = {0};

    for (int i = numLen - 1, j = 0; i >= 0; i--)
    {
        num[j++] = numStr[i] - '0';
    }

    int res[MAX_DIGITS] = {0};
    res[0] = 1;

    for (int i = 0; i < pow; i++)
    {
        int carry = 0;
        for (int j = 0; j < MAX_DIGITS; j++)
        {
            int prod = res[j] * 2 + carry;
            res[j] = prod % 10;
            carry = prod / 10;
        }
    }

    int idx = MAX_DIGITS - 1;
    while (idx >= 0 && res[idx] == 0)
    {
        idx--;
    }

    int k = 0;
    for (int i = idx; i >= 0; i--)
    {
        result[k++] = res[i] + '0';
    }
    result[k] = '\0';
}

int main()
{
    char numStr[MAX_DIGITS];
    char result[MAX_DIGITS];
    int pow;

    while (scanf("%s %d", numStr, &pow) == 2)
    {
        powerToPlainString(numStr, pow, result);
        printf("%s\n", result);
    }

    return 0;
}
