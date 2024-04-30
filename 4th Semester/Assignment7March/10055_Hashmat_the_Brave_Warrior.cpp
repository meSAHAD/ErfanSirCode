#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int a, b;
    while (scanf("%lld %lld", &a, &b) == 2)
    {
        long long int c = labs(a - b);
        printf("%lld\n", c);
    }
    return 0;
}
