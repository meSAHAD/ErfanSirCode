#include <stdio.h>

#define MAXN 30000

int main()
{
    int test;
    scanf("%d", &test);

    while (test--)
    {
        int n, m;
        scanf("%d %d", &n, &m);

        int id[MAXN], sz[MAXN];
        for (int i = 0; i < n; i++)
        {
            id[i] = i;
            sz[i] = 1;
        }

        int max_size = 1;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a--;
            b--;

            // Finding the root of sets containing a and b
            while (a != id[a])
                a = id[a];
            while (b != id[b])
                b = id[b];

            // If they belong to the same set, continue
            if (a == b)
                continue;

            // Merge the smaller set into the larger set
            if (sz[a] < sz[b])
            {
                id[a] = b;
                sz[b] += sz[a];
                if (sz[b] > max_size)
                    max_size = sz[b];
            }
            else
            {
                id[b] = a;
                sz[a] += sz[b];
                if (sz[a] > max_size)
                    max_size = sz[a];
            }
        }

        printf("%d\n", max_size);
    }

    return 0;
}