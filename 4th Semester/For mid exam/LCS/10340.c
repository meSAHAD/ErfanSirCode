#include <stdio.h>
#include <string.h>

int main()
{
    char n[100000], x[100000], y = NULL;
    int len = 0, i = 0, j = 0, k = 0, m = 0, lenn = 0, ck = 0;
    while (scanf("%s%s", n, x) == 2)
    {
        len = strlen(n);
        lenn = strlen(x);
        if (len > lenn)
            printf("No\n");
        else
        {
            for (i = 0; i < len; i++)
            {
                for (j = m; j < lenn; j++)
                {
                    if (n[i] == x[j])
                    {
                        m = j + 1;
                        ck++;
                        break;
                    }
                }
            }
            if (ck == len)
                printf("Yes\n");
            else
                printf("No\n");
        }
        ck = 0;
        m = 0;
    }
    return 0;
}