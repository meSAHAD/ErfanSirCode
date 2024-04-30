#include <stdio.h>

int main()
{
    int n;
    while (1)
    {
        scanf("%d", &n);
        if (n < 0)
            break;
        else if (n == 0)
            printf("0\n");
        else
        {
            int ternary[32];
            int i = 0;
            while (n > 0)
            {
                ternary[i] = n % 3;
                n = n / 3;
                i++;
            }
            int j;
            for ( j = i - 1; j >= 0; j--)
            {
                printf("%d", ternary[j]);
            }
            printf("\n");
        }
    }
    return 0;
}
