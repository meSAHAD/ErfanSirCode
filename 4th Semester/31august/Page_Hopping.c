// status: Accepted


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int graph[110][110];
int  i,j,k,T, N, a, b;

int main()
{
    while (scanf("%d %d", &a, &b) == 2)
    {
        if (a == 0 && b == 0)
            break;
        T++;
        for (i = 0; i < 100; i++)
        {
            for (j = 0; j < 100; j++)
            {
                if (i == j)
                    graph[i][j] = 0;
                else
                    graph[i][j] = 100000;
            }
        }

        N = 0;
        for (;;)
        {
          
            N = a > N ? (a > b ? a : b) : (b > N ? b : N);
            graph[a - 1][b - 1] = 1;
            scanf("%d %d", &a, &b);
            if (a == 0 && b == 0)
                break;
        }

     
        for ( k = 0; k < N; k++)
        {
            for (i = 0; i < N; i++)
            {
                for (j = 0; j < N; j++)
                {
                    if (graph[i][j] > graph[i][k] + graph[k][j])
                    {
                        graph[i][j] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }

        int P = 0;
        int sum = 0;
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (i != j && graph[i][j] != 100000)
                {
                    P++;
                    sum += graph[i][j];
                }
            }
        }

        printf("Case %d: average length between pages = %1.3f clicks\n", T, (float)sum / P);
    }

    return 0;
}
