#include<stdio.h>
long int factorial(int n);    //recurssion
long int factorial(int n) {
    if (n>=1)
        return n*factorial(n-1);
    else
        return 1;
}
int suma(int a)                  //summation
{
    int suma=0;
    for(int i=1;i<=a;i++)
    {
        suma=suma+i;
    }
    return suma;
}
int product(int x)            //product
{
    int product =1;
        for(int i=1;i<=x;i++)
    {
        product = product *i;
    }
    return product;

}
int main() {

    //freopen("erfansir.txt","r",stdin);
    int n,N;
     scanf("%d",&N);
    for (int j=1;j<=N;j++){
    //printf("Enter a positive integer: ");
    scanf("%d",&n);
    printf("Factorial of %d = %ld\n", n, factorial(n));
     printf("Summation of %d = %ld\n", n, suma(n));
     printf("product of %d = %ld\n\n", n, product(n));
    }
    return 0;
}

