#include <stdio.h>

int main()
{
    long long int n;
    int rem, sum;
    while (1)
    {
        scanf("%lld", &n);
        if (n == 0)
            break;
    function:
        sum = 0;
        while (n != 0)
        {
            rem = n % 10;
            sum = sum + rem;
            n = n / 10;
        }
        if (sum < 10)
            printf("%d\n", sum);
        else
        {
            n = sum;
            goto function;
        }
    }
    return 0;
}
