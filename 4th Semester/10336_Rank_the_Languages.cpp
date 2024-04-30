#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 105

typedef struct ANS
{
    int num;
    char ch;
} ANS;

int n, m;
char s[N][N], ch;

ANS ans[26];

int cmp(const void *a, const void *b)
{
    const ANS *pa = (const ANS *)a;
    const ANS *pb = (const ANS *)b;
    return (pa->num > pb->num) ? -1 : (pa->num < pb->num) ? 1
                                  : (pa->ch < pb->ch)     ? -1
                                  : (pa->ch > pb->ch)     ? 1
                                                          : 0;
}

void DFS(int u, int v)
{
    if (u < 0 || u >= n || v < 0 || v >= m || s[u][v] != ch)
        return;

    s[u][v] = '*';
    DFS(u - 1, v);
    DFS(u, v - 1);
    DFS(u + 1, v);
    DFS(u, v + 1);
}

int main()
{
    int i, j, k, kase;
    scanf("%d", &kase);
    for (int t = 1; t <= kase; t++)
    {
        scanf("%d %d", &n, &m);
        getchar();
        for (i = 0; i < n; i++)
            gets(s[i]);

        for (i = 0; i < 26; i++)
        {
            ans[i].num = 0;
            ans[i].ch = i + 97;
        }
        for (i = 0; i < n; i++)
            for (j = 0; j < m; j++)
                if (s[i][j] != '*')
                {
                    ch = s[i][j];
                    DFS(i, j);
                    ans[ch - 97].num++;
                }
        qsort(ans, 26, sizeof(ANS), cmp);
        printf("World #%d\n", t);
        i = 0;
        while (i < 26 && ans[i].num != 0)
        {
            printf("%c: %d\n", ans[i].ch, ans[i].num);
            i++;
        }
    }
    return 0;
}
