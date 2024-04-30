#include <stdio.h>

int main()
{
    int t, i = 1;
    scanf("%d", &t);
    while (t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        long long sum = 0;
        int j;
        for ( j = a; j <= b; j++)
        {
            if (j % 2 != 0)
                sum += j;
        }
        printf("Case %d: %lld\n", i, sum);
        i++;
    }
    return 0;
}
