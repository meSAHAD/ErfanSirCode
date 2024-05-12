#include <stdio.h>
#include <string.h>
#define N 25

int i, j;
char a[N], b[N];
int dp[N][N], p[N][N];

int min(int i, int j, int *s)
{
    int f, k;
    for (k = 1; k <= 3; k++)
        if (s[k] < dp[i][j])
        {
            dp[i][j] = s[k];
            f = k;
        }
    if (f == 3 && a[i] == b[j])
        f = 0;
    return f;
}

void print(int i, int j)
{

    if (!i && !j)
        return;
    else if (p[i][j] == 1)
    {
        print(i - 1, j);
        printf("D%c%02d", a[i], j + 1);
        return;
    }
    else if (p[i][j] == 2)
    {
        print(i, j - 1);
        printf("I%c%02d", b[j], j);
        return;
    }
    else if (p[i][j] == 0)
    {
        print(i - 1, j - 1);
        return;
    }
    else
    {
        print(i - 1, j - 1);
        printf("C%c%02d", b[j], j);
        return;
    }
}

int main()
{
    int lena, lenb;
    while (1)
    {
        scanf("%s", a + 1);
        if (a[1] == '#')
            break;
        scanf("%s", b + 1);
        lena = strlen(a + 1);
        lenb = strlen(b + 1);
        memset(dp, 0x3f, sizeof(dp));
        memset(p, -1, sizeof(p));
        for (i = 0; i <= lena; i++)
        {
            dp[i][0] = i;
            p[i][0] = 1;
        }
        for (i = 0; i <= lenb; i++)
        {
            dp[0][i] = i;
            p[0][i] = 2;
        }

        for (i = 1; i <= lena; i++)
            for (j = 1; j <= lenb; j++)
            {
                int s[4];
                s[1] = dp[i - 1][j] + 1;
                s[2] = dp[i][j - 1] + 1;
                s[3] = dp[i - 1][j - 1] + (a[i] == b[j] ? 0 : 1);
                p[i][j] = min(i, j, s);
            }

        print(lena, lenb);
        printf("E\n");
    }
    return 0;
}