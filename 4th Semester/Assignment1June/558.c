#include <stdio.h>
#include <memory.h>
#define MAXV 1004
#define MAXE 2008
#define INF 0x7f7f7f7f

typedef struct
{
    int u, v, w;
} Edge;

Edge e[MAXE];
int n, m, d[MAXV], pre[MAXV];

int relax(int u, int v, int w)
{
    if (d[v] > d[u] + w)
    {
        d[v] = d[u] + w;
        pre[v] = u;
        return 1;
    }
    return 0;
}

int bellman_ford(int s)
{
    int i, j, flag;
    memset(pre, -1, sizeof(pre));
    memset(d, 0x7f, sizeof(d));
    d[s] = 0;
    for (i = 0; i < n; i++)
    {
        flag = 1;
        for (j = 0; j < m; j++)
            if (relax(e[j].u, e[j].v, e[j].w))
                flag = 0;
        if (flag)
            break;
    }
    for (j = 0; j < m; j++)
        if (relax(e[j].u, e[j].v, e[j].w))
            return 0;
    return 1;
}

int main()
{
    int T, i;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (i = 0; i < m; i++)
            scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        if (bellman_ford(0))
            printf("not possible\n");
        else
            printf("possible\n");
    }
    return 0;
}