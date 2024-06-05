#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N_STRLEN 100005

char str[N_STRLEN];

int main(int argc, char *argv[])
{
    int k, len, L, R, left;
    char last;

    while (scanf("%s", str) == 1)
    {
        len = strlen(str);
        last = str[len - 1];
        left = len - 1;
        for (k = 0; k < len; k++)
        {
            if (str[k] != last)
                continue;
            L = k;
            R = len - 1;
            while (L <= R)
            {
                if (str[L] != str[R])
                    break;
                L++;
                R--;
            }
            if (L > R)
            {
                left = k;
                break;
            }
        }
        printf("%s", str);
        for (k = left - 1; k >= 0; k--)
            putchar(str[k]);
        putchar('\n');
    }

    return 0;
}
