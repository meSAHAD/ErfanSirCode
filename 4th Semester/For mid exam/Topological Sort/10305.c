#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sz 100

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("H:\\C_Codes\\input.txt","r",stdin);
#endif
    int i, j, m, n, vertex, edge, tsk1, tsk2;

    while (scanf("%d %d", &vertex, &edge) == 2)
    {
        if (vertex == 0 && edge == 0)
            break;

        int deg[101] = {0};
        int v[101][sz]; // Adjacency list
        memset(v, 0, sizeof(v));

        for (i = 0; i < edge; i++)
        {
            scanf("%d %d", &tsk1, &tsk2);
            v[tsk1][deg[tsk1]++] = tsk2;
            deg[tsk2]++;
        }

        int q[sz], front = 0, rear = 0;
        for (i = 1; i <= vertex; i++)
            if (deg[i] == 0)
                q[rear++] = i;

        while (front != rear)
        {
            int f = q[front++];
            printf("%d ", f);
            for (i = 0; i < deg[f]; i++)
            {
                int child = v[f][i];
                deg[child]--;
                if (deg[child] == 0)
                    q[rear++] = child;
            }
        }
        printf("\n");
    }
    return 0;
}
