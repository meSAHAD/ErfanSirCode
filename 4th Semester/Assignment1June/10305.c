#include <stdio.h>
#include <string.h>

int f[105][105];
int v[105];
int n, m;

void topo()
{
    int count = 0, i, j;
    while (count < n)
    {
        for (i = 1; i <= n; i++)
        {
            if (!v[i])
            {
                v[i] = -1;
                printf("%d", i);
                count++;
                if (count != n)
                    printf(" ");
                else
                    printf("\n");
                for (j = 1; j <= n; j++)
                {
                    if (i != j && f[i][j])
                    {
                        f[i][j] = 0;
                        v[j]--;
                    }
                }
            }
        }
    }
}

int main()
{
    int i;
    while (scanf("%d%d", &n, &m))
    {
        if (!m && !n)
            break;
        memset(f, 0, sizeof(f));
        memset(v, 0, sizeof(v));
        for (i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            f[a][b] = 1;
            v[b]++;
        }
        topo();
    }
    return 0;
}