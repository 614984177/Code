#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
#define X first
#define Y second
int n, k, deg[MAXN], D, ans[MAXN];
vector<pair<int, int>> G[MAXN];
void dfs(int u, int fa, int pre)
{
    int color = -1;
    for (auto i : G[u])
    {
        if (i.X == fa) continue;
        color = (color + 1) % D;
        if (color == pre) color = (color + 1) % D;
        ans[i.Y] = color;
        dfs(i.X, u, color);
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        G[u].emplace_back(v, i);
        G[v].emplace_back(u, i);
        deg[u]++, deg[v]++;
    }
    sort(deg + 1, deg + 1 + n, [](int a, int b){ return a > b; });
    D = deg[k + 1];
    dfs(1, -1, -1);
    printf("%d\n", D);
    for (int i = 0; i < n - 1; i++) printf("%d ", ans[i] + 1);
    return 0;
}
/*
6 2
1 4
4 3
3 5
3 6
5 2
*/