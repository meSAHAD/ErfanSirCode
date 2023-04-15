#include<stdio.h>
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
int main() {
    freopen("gcd.txt","r",stdin);
    int a, b;
    scanf("%d%d", & a, & b);
    int gc=gcd(a, b);
    printf("GCD: %d\n",gc );

    return 0;
 }
