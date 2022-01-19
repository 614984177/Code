#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m, d, fa[MAXN];
vector<int> G[MAXN];
bool vis[MAXN];
void dfs(int u)
{
    vis[u] = true;
    for (auto v : G[u])
    {
        if (vis[v]) continue;
        if (u == 1) d--;
        fa[v] = u;
        dfs(v);
    }
}
int main()
{
    scanf("%d%d%d", &n, &m, &d);
    while (m--)
    {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (G[1].size() < d) { printf("NO\n"); return 0; }
    dfs(1);
    if (d < 0) { printf("NO\n"); return 0; }
    for (auto v : G[1])
    {
        if (fa[v] != 1 && d)
        {
            fa[v] = 1;
            d--;
        }
    }
    printf("YES\n");
    for (int i = 2; i <= n; i++) printf("%d %d\n", fa[i], i);
    return 0;
}
/*
4 5 1
1 2
1 3
1 4
2 3
3 4
*/