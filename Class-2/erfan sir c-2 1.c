#include<stdio.h>
int main()
{
    int n,N,j ,sum=0,suma=1;
    scanf("%d",&N);
    for (j=1;j<=N;j++){
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        sum=sum+i;
    }
     for (int i=1;i<=n;i++)
    {
        suma=suma*i;
    }
    printf("Summation is %d\n",sum);
    printf("Factorial result is %d\n",suma);
}
}
