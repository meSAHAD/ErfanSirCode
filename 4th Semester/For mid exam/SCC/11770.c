#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 10005
#define clr(a) memset(a, 0, sizeof(a))

int v[N][N];
int store[N];
bool color[N];

void dfs(int u)
{
    color[u] = true;
    for (int i = 0; i < N; i++)
    {
        int V = v[u][i];
        if (V != 0 && !color[V])
            dfs(V);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    int c = 1;
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        clr(color);
        for (int i = 0; i <= n; i++)
        {
            clr(v[i]);
            store[i] = 0;
        }
        while (m--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            v[x][store[x]++] = y;
        }
        int M = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!color[i])
            {
                dfs(i);
                store[++M] = i;
            }
        }
        clr(color);
        M = 0;
        for (int i = n; i > 0; i--)
        {
            if (!color[store[i]])
            {
                dfs(store[i]);
                M++;
            }
        }
        printf("Case %d: %d\n", c++, M);
    }
    return 0;
}
