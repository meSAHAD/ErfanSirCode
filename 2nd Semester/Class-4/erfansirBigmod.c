#include<stdio.h>
int Bigmod(int a, int b, int c)
{
    if(b==0) return 1;
    if(b%2==0)
    {
        int x=Bigmod(a,b/2,c);
        return (x*x)%c;
    }
    else return (a%c * Bigmod(a,b-1,c))%c;
}

int main()
{
    //freopen("gcd.txt", "r", stdin);
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("%d",Bigmod(a,b,c));
    return 0;
}
