#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
using namespace std;
#define N 10005
#define pb push_back
#define clr(a) memset(a, 0, sizeof(a))
using namespace std;
vector<int> v[N];
vector<int> store;
bool color[N];
void dfs(int u)
{
    color[u] = true;
    for (int i = 0; i < v[u].size(); i++)
    {
        int V = v[u][i];
        if (!color[V])
            dfs(V);
    }
}
int main()
{
    int t;
    int n, m;
    cin >> t;
    int c = 1;
    while (t--)
    {
        scanf("%d %d", &n, &m);
        clr(color);
        for (int i = 0; i <= n; i++)
            v[i].clear();
        store.clear();
        while (m--)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            v[x].pb(y);
        }
        int M = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!color[i])
                dfs(i), store.pb(i);
        }
        clr(color);
        M = 0;
        for (int i = store.size() - 1; i >= 0; i--)
        {
            if (!color[store[i]])
            {
                dfs(store[i]);
                M++;
            }
        }
        printf("Case %d: %d", c, M);
        cout << endl;
        c++;
    }
    return 0;
}