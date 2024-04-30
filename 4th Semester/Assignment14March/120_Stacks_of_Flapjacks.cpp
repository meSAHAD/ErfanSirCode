#include <stdio.h>
int i,j;
int a[102], b[102], n, p, total, Max;
void swap(int x)
{
    int i, j, t;
    for (i = 0, j = x; j > i; j--, i++)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
int main()
{
    while (scanf("%d", &a[0]) == 1)
    {
        n = 1;
        while (1)
        {
            if (getchar() != ' ')
                break;
            scanf("%d", &a[n]);
            n++;
        }
        printf("%d", a[0]);
        for ( i = 1; i < n; i++)
            printf(" %d", a[i]);
        printf("\n");
        total = 0;
        for ( i = 0; i < n; i++)
        {
            Max = 0;
            for ( j = n - i - 1; j >= 0; j--)
                if (Max < a[j])
                {
                    Max = a[j];
                    p = j;
                }
            if (p != n - i - 1)
            {
                if (p != 0)
                {
                    swap(p);
                    b[total++] = n - p;
                }
                swap(n - i - 1);
                b[total++] = i + 1;
            }
        }
        if (total == 0)
            printf("%d\n", 0);
        else
        {
            for ( i = 0; i < total; i++)
                printf("%d ", b[i]);
            printf("%d\n", 0);
        }
    }
    return 0;
}