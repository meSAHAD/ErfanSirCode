#include <stdio.h>
#include <string.h>

#define MAXN 1000000
int i, j;

char s[MAXN], res[MAXN], *acgt = "ACGT";
int M[300], n, id, resLen, resCnt;
int to[MAXN][4], cnt[MAXN];

void clear(int i)
{
    cnt[i] = 0;
    for (j = 0; j < 4; j++)
        to[i][j] = -1;
}

void add(int i, char *x)
{
    cnt[i]++;
    if (!*x)
        return;
    int ni = to[i][M[*x]];
    if (ni == -1)
    {
        ni = id++;
        clear(ni);
        to[i][M[*x]] = ni;
    }
    add(ni, x + 1);
}

void rec(int i, int depth)
{
    s[depth] = 0;
    if (depth > resLen && cnt[i] > 1)
    {
        resLen = depth;
        resCnt = cnt[i];
        strcpy(res, s);
    }
    int j;
    for (j = 0; j < 4; j++)
    {
        int ni = to[i][j];
        if (ni != -1)
        {
            s[depth] = acgt[j];
            rec(ni, depth + 1);
        }
    }
}

int main()
{
    M['A'] = 0;
    M['C'] = 1;
    M['G'] = 2;
    M['T'] = 3;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%s", s);
        clear(0);
        id = 1;
        int len = strlen(s);
        for (i = 0; i < len; i++)
            add(0, s + i);
        resLen = resCnt = 0;
        rec(0, 0);
        if (resLen > 0)
            printf("%s %d\n", res, resCnt);
        else
            puts("No repetitions found!");
    }
    return 0;
}
