#include <stdio.h>
#include <stdlib.h>

#define MAXN 200

long long int pr[MAXN], n, m, mst, s[MAXN];
long long int e[MAXN][3]; // Array to store edges

long long int find_set(long long int r)
{
    if (pr[r] == r)
        return r;
    else
        return find_set(pr[r]);
}

int cmp(const void *a, const void *b)
{
    return *((long long int *)a + 2) - *((long long int *)b + 2);
}

long long int kruskal()
{
    qsort(e, m, sizeof(e[0]), cmp);
    long long int cnt = 0;

    for (long long int i = 0; i < m && cnt < n - 1; i++)
    {
        long long int u = find_set(e[i][0]);
        long long int v = find_set(e[i][1]);

        if (u != v)
        {
            if (s[u] > s[v])
            {
                long long int temp = u;
                u = v;
                v = temp;
            }
            s[v] += s[u];
            mst += e[i][2];
            pr[u] = v;
            cnt++;
        }
    }
}

int main()
{
    long long int u, v, w;
    while (scanf("%lld %lld", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
            break;
        mst = 0;
        long long int total = 0;
        for (long long int i = 0; i < m; i++)
        {
            pr[i] = i;
            s[i] = 1;
            scanf("%lld %lld %lld", &u, &v, &w);
            total += w;
            e[i][0] = u;
            e[i][1] = v;
            e[i][2] = w;
        }
        s[m] = 1;
        pr[m] = m;
        kruskal();
        printf("%lld\n", total - mst);
    }
    return 0;
}
