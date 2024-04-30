#include <stdio.h>

int main()
{
    int n, a, b, c;
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        if ((a > b && a < c) || (a < b && a > c))
        {
            printf("Case %d: %d\n", i + 1, a);
        }

        if ((b > a && b < c) || (b < a && b > c))
        {
            printf("Case %d: %d\n", i + 1, b);
        }

        if ((c > a && c < b) || (c < a && c > b))
        {
            printf("Case %d: %d\n", i + 1, c);
        }
    }

    return 0;
}