#include <stdio.h>

int mod(int a, int b, int c)
{
    if (b == 0)
        return 1;

    if (b % 2 == 0)
    {
        int x = mod(a, b / 2, c);
        return (x * x) % c;
    }
    else
        return (a % c * mod(a, b - 1, c)) % c;
}

int main()
{
    int B, P, M;

    while (scanf("%d %d %d", &B, &P, &M) != EOF)
        printf("%d\n", mod(B, P, M));

    return 0;
}
