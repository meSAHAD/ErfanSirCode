#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SZ 100

int row, col;
char ar[SZ][SZ];
char ch;
char v[SZ * SZ];

typedef struct
{
    char a;
    int b;
} str;

str data[65];

int xx[] = {-1, 0, 0, 1};
int yy[] = {0, -1, 1, 0};

void dfs(int i, int j, char ch);
int cmp(const void *a, const void *b);

int main()
{
    int t, i, j, k, l, cnt, z;
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        z = -1;
        scanf("%d %d", &row, &col);
        getchar();
        for (j = 0; j < row; j++)
            gets(ar[j]);
        for (j = 0; j < row; j++)
        {
            for (k = 0; k < col; k++)
            {
                if (ar[j][k] != '.')
                {
                    v[j * col + k] = ar[j][k];
                    ch = ar[j][k];
                    dfs(j, k, ch);
                }
            }
        }
        qsort(data, z + 1, sizeof(data[0]), cmp);
        printf("World #%d\n", i);
        for (j = 0; j <= z; j++)
            printf("%c: %d\n", data[j].a, data[j].b);
    }
    return 0;
}

void dfs(int i, int j, char ch)
{
    int a, b;
    if (ar[i][j] == ch && i >= 0 && i < row && j >= 0 && j < col)
    {
        ar[i][j] = '.';
        for (int k = 0; k < 4; k++)
        {
            a = i + xx[k];
            b = j + yy[k];
            dfs(a, b, ch);
        }
    }
    return;
}

int cmp(const void *a, const void *b)
{
    str x = *(str *)a;
    str y = *(str *)b;
    if (x.b > y.b)
        return 1;
    else if (x.b == y.b)
    {
        if (x.a < y.a)
            return -1;
        else if (x.a > y.a)
            return 1;
    }
    else
        return -1;
    return 0;
}
