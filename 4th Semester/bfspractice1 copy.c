#include <stdio.h>
#include <stdbool.h>

#define N 1005
int adj[N][N];
bool visited[N];

void bfs(int s, int n)
{
    int queue[N], front = 0, rear = -1;
    queue[++rear] = s;
    visited[s] = true;

    while (front <= rear)
    {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 1; v <= n; v++)
        {
            if (adj[u][v] && !visited[v])
            {
                queue[++rear] = v;
                visited[v] = true;
            }
        }
    }
}

int main()
{
    freopen("bfsinput.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    bfs(1, n);
    return 0;
}
