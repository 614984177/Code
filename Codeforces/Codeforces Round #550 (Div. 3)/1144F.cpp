#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
#define X first
#define Y second
int n, m, d[MAXN];
vector<pair<int, int>> G[MAXN];
bool ans[MAXN];
void dfs(int u, bool col)
{
    for (auto i : G[u])
    {
        int v = i.X, id = i.Y;
        if ((id&1) != col) ans[id / 2] = 1;
        else ans[id / 2] = 0;
        if (d[v])
        {
            if ((d[u] - d[v] + 1) % 2 == 1) { printf("NO\n"); exit(0); }
            continue;
        }
        d[v] = d[u] + 1;
        dfs(v, !col);
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        G[u].emplace_back(v, i * 2);
        G[v].emplace_back(u, i * 2 + 1);
    }
    d[1] = 1;
    dfs(1, 1);
    printf("YES\n");
    for (int i = 0; i < m; i++) printf("%d", ans[i]);
    return 0;
}
/*
6 5
1 5
2 1
1 4
3 1
6 1
*/