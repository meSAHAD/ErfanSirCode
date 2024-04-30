#include <stdio.h>
#include <string.h>

#define mx 1001
char a[mx], b[mx];
int dp[mx][mx];
char visited[mx][mx];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int lcs(int i, int j)
{
    if (a[i] == '\0' || b[j] == '\0')
        return 0;
    if (visited[i][j])
        return dp[i][j];
    int ans = 0;
    if (a[i] == b[j])
        ans = 1 + lcs(i + 1, j + 1);
    else
        ans = max(lcs(i, j + 1), lcs(i + 1, j));
    visited[i][j] = 1;
    dp[i][j] = ans;
    return dp[i][j];
}

int main()
{
    while (gets(a) && gets(b))
    {
        memset(visited, 0, sizeof(visited));
        printf("%d\n", lcs(0, 0));
    }
    return 0;
}
