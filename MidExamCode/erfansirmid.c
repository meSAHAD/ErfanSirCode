#include<stdio.h>
int factorial(int n)  //factorial with recursion
{

    if(n == 0)
    {
        return 1;
    }
    else
    {
        return n * factorial(n-1);
    }
}

int fibbonacci(int n)  //fibbonacci number with recursion
{
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    else
    {
        return (fibbonacci(n-1) + fibbonacci(n-2));
    }
}
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

     //lcm shortcut= (a*b)/gcd

int lcm(int a, int b)  //lcm with recursion
{
    static int result = 0;
    result = result + b;
    if((result % a == 0) && (result % b == 0))
    {
        return result;
    }
    else
    {
        return lcm(a, b);
    }
}
int bigmod(int a, int b, int c)
{
    if(b==0) return 1;
    if(b%2==0)
    {
        int x=bigmod(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * bigmod(a,b-1,c))%c;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d\n",factorial(a));
    printf("%d\n",fibbonacci(a));
    printf("%d\n",gcd(a,b));
    printf("%d\n",lcm(a,b));
    printf("%d\n",bigmod(a,b,c));
    return 0;
}

