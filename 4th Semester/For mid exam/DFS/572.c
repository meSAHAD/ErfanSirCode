#include <stdio.h>
#include <string.h>

#define SZ 105

int vis[SZ][SZ];
char ar[SZ][SZ];
int q1[SZ * SZ], q2[SZ * SZ];

void mark(int i, int j, int m, int n)
{
    if (ar[i][j + 1] == '@' && !vis[i][j + 1])
    {
        vis[i][j + 1] = 1;
        q1[0] = i;
        q2[0] = j + 1;
    }
    if (ar[i][j - 1] == '@' && !vis[i][j - 1])
    {
        vis[i][j - 1] = 1;
        q1[0] = i;
        q2[0] = j - 1;
    }
    if (ar[i - 1][j] == '@' && !vis[i - 1][j])
    {
        vis[i - 1][j] = 1;
        q1[0] = i - 1;
        q2[0] = j;
    }
    if (ar[i + 1][j] == '@' && !vis[i + 1][j])
    {
        vis[i + 1][j] = 1;
        q1[0] = i + 1;
        q2[0] = j;
    }

    if (ar[i - 1][j - 1] == '@' && !vis[i - 1][j - 1])
    {
        vis[i - 1][j - 1] = 1;
        q1[0] = i - 1;
        q2[0] = j - 1;
    }
    if (ar[i + 1][j + 1] == '@' && !vis[i + 1][j + 1])
    {
        vis[i + 1][j + 1] = 1;
        q1[0] = i + 1;
        q2[0] = j + 1;
    }
    if (ar[i - 1][j + 1] == '@' && !vis[i - 1][j + 1])
    {
        vis[i - 1][j + 1] = 1;
        q1[0] = i - 1;
        q2[0] = j + 1;
    }
    if (ar[i + 1][j - 1] == '@' && !vis[i + 1][j - 1])
    {
        vis[i + 1][j - 1] = 1;
        q1[0] = i + 1;
        q2[0] = j - 1;
    }
    return;
}

int main()
{
    int m, n, i, j, x, y;
    int cnt = 0;
    while (scanf("%d %d", &m, &n) == 2)
    {
        getchar();
        if (m == 0 && n == 0)
            break;
        for (int i = 1; i <= m; i++)
            gets(ar[i]);
        memset(vis, 0, sizeof(vis));
        for (int i = 1; i <= m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (ar[i][j] == '@' && !vis[i][j])
                {
                    cnt++;
                    mark(i, j, m, n);
                    int front = 0, rear = 1;
                    while (front < rear)
                    {
                        x = q1[front];
                        y = q2[front++];
                        mark(x, y, m, n);
                    }
                }
            }
        }
        printf("%d\n", cnt);
        cnt = 0;
    }
    return 0;
}
