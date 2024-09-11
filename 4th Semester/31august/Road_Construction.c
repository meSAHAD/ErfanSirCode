// status: wrong answer

#include <stdio.h>
#include <math.h>
#include <limits.h>

#define MX 55
#define INF INT_MAX

double g[MX][MX];
int point_x[MX], point_y[MX];

double dis(int ax, int ay, int bx, int by)
{
    double x = ax - bx, y = ay - by;
    return sqrt(x * x + y * y);
}

void reset()
{
    int i, j;
    for (i = 0; i < MX; i++)
    {
        for (j = 0; j < MX; j++)
        {
            if (i == j)
                g[i][j] = 0;
            else
                g[i][j] = INF;
        }
    }
}

int main()
{
    int n, m, x, y;
    while (scanf("%d %d", &n, &m) && (n + m))
    {
        int i, j;
        for (i = 1; i <= n; i++)
        {
            scanf("%d %d", &point_x[i], &point_y[i]);
        }

        reset();
        for (j = 1; j <= m; j++)
        {
            scanf("%d %d", &x, &y);
            g[x][y] = g[y][x] = dis(point_x[x], point_y[x], point_x[y], point_y[y]);
        }

        int k;
        for (k = 1; k <= n; k++)
        {
            for (i = 1; i <= n; i++)
            {
                for (j = 1; j <= n; j++)
                {
                    if (g[i][k] < INF && g[k][j] < INF)
                    {
                        if (g[i][j] > g[i][k] + g[k][j])
                        {
                            g[i][j] = g[i][k] + g[k][j];
                        }
                    }
                }
            }
        }

  
        double sum, d, mx = 0;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (g[i][j] == INF)
                    continue;

                sum = 0;
                d = dis(point_x[i], point_y[i], point_x[j], point_y[j]);
                int u, v;
                for (u = 1; u <= n; u++)
                {
                    for (v = 1; v <= n; v++)
                    {
                        sum += g[u][v] - fmin(g[u][v], fmin(g[u][i] + d + g[j][v], g[u][j] + d + g[i][v]));
                    }
                }

                if (sum > mx)
                {
                    mx = sum;
                    x = i;
                    y = j;
                }
            }
        }

        if (mx == 0)
            printf("No road required\n");
        else
            printf("%d %d\n", x, y);
    }

    return 0;
}
