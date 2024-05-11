#include <stdio.h>
#include <string.h>

#define MAX_C 10000

int d[MAX_C], par[MAX_C];

int find(int x)
{
    if (par[x] == x)
    {
        return x;
    }
    else
    {
        int representative = find(par[x]);
        par[x] = representative;
        return representative;
    }
}

void _union(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y)
    {
        par[x] = y;
        d[y] += d[x];
    }
}

int main()
{
    while (1)
    {
        int c, r;
        scanf("%d %d", &c, &r);
        if (c == 0 && r == 0 || c == 0)
            break;
        else
        {
            char chain[MAX_C][25];
            for (int i = 0; i < c; i++)
            {
                scanf("%s", chain[i]);
                par[i] = i;
                d[i] = 1;
            }
            for (int i = 0; i < r; i++)
            {
                char inferior[25], predator[25];
                scanf("%s %s", inferior, predator);
                int inferior_idx = -1, predator_idx = -1;
                for (int j = 0; j < c; j++)
                {
                    if (strcmp(chain[j], inferior) == 0)
                    {
                        inferior_idx = j;
                    }
                    if (strcmp(chain[j], predator) == 0)
                    {
                        predator_idx = j;
                    }
                }
                _union(inferior_idx, predator_idx);
            }
            int a = 0;
            for (int i = 0; i < c; i++)
            {
                if (d[i] > a)
                {
                    a = d[i];
                }
            }
            printf("%d\n", a);
        }
    }
    return 0;
}
