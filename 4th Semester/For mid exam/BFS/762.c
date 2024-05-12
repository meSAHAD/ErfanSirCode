#include <stdio.h>
#include <string.h>

#define sz 1003

int path[sz], start, to;
int flag[sz];
int mat[sz][sz];
int queue[sz];
int front, rear;
char mps[sz][11];
char mpi[sz][11];

void bfs(void);

int main()
{
    // freopen("in.txt","r",stdin);
    int tst, i, j, k, nd;
    int chk = 1;
    char s1[11], s2[11];
    while (scanf("%d", &nd) != EOF)
    {
        memset(flag, 0, sizeof(flag));
        memset(path, 0, sizeof(path));
        memset(mat, 0, sizeof(mat));
        front = 0, rear = 0;
        j = 1;
        for (i = 1; i <= nd; i++)
        {
            scanf("%s %s", s1, s2);
            int idx1 = -1, idx2 = -1;
            for (k = 1; k < j; k++)
            {
                if (strcmp(mps[k], s1) == 0)
                    idx1 = k;
                if (strcmp(mps[k], s2) == 0)
                    idx2 = k;
            }
            if (idx1 == -1)
            {
                strcpy(mps[j], s1);
                idx1 = j++;
            }
            if (idx2 == -1)
            {
                strcpy(mps[j], s2);
                idx2 = j++;
            }
            mat[idx1][idx2] = 1;
            mat[idx2][idx1] = 1;
        }
        scanf("%s %s", s1, s2);
        int idx3 = -1, idx4 = -1;
        for (k = 1; k < j; k++)
        {
            if (strcmp(mps[k], s1) == 0)
                idx3 = k;
            if (strcmp(mps[k], s2) == 0)
                idx4 = k;
        }
        if (idx3 == -1)
        {
            strcpy(mps[j], s1);
            idx3 = j++;
        }
        if (idx4 == -1)
        {
            strcpy(mps[j], s2);
            idx4 = j++;
        }
        start = idx3;
        to = idx4;
        queue[rear++] = to;
        bfs();
        flag[to] = 1;
        if (chk == 0)
            printf("\n");
        chk = 0;
        if (path[start] == 0)
            printf("No route\n");
        else
        {
            while (start != to)
            {
                printf("%s %s\n", mpi[start], mpi[path[start]]);
                start = path[start];
            }
        }
        for (i = 1; i < j; i++)
            memset(mat[i], 0, sizeof(mat[i]));
    }
    return 0;
}

void bfs(void)
{
    int tp, i, j;
    while (front < rear)
    {
        tp = queue[front++];
        for (j = 1; j < sz; j++)
        {
            if (mat[tp][j] && !flag[j])
            {
                path[j] = tp;
                if (j == start)
                    return;
                queue[rear++] = j;
                flag[j] = 1;
            }
        }
    }
}
