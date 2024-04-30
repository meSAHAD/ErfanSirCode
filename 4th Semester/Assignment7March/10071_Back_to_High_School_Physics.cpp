#include <stdio.h>

int main()
{
    int v, t;
    while (scanf("%d %d", &v, &t) == 2)
    {
        int disp = 2 * v * t;
        printf("%d\n", disp);
    }
    return 0;
}
