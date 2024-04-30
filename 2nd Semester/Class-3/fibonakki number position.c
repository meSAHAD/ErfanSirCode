#include<stdio.h>
int fib(n)
{
    if (n==1)
    {
        return 0;
    }
    if (n==2)
    {
        return 1;
    }
    else
    {

        return fib(n-1)+fib(n-2);
    }
}

int main()
{
    int a;
    scanf("%d", &a);

    int m=fib(a);

    printf("%d", m);
}
