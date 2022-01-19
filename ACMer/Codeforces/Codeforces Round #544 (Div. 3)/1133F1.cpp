#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m, pa[MAXN];
vector<int> G[MAXN];
int Find (int x) { return pa[x] == x ? x : pa[x] = Find(pa[x]); }
int main()
{
    scanf("%d%d", &n, &m);
    int pos = 0;
    while (m--)
    {
        int u, v; scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        if (G[u].size() > G[pos].size()) pos = u;
        if (G[v].size() > G[pos].size()) pos = v;
    }
    vector<pair<int, int> > ans;
    for (int i = 1; i <= n; i++) pa[i] = i;
    for (auto i : G[pos]) pa[i] = pos, ans.emplace_back(pos, i);
    for (int u = 1; u <= n; u++)
    {
        for (auto v : G[u])
        {
            int rt1 = Find(u), rt2 = Find(v);
            if (rt1 != rt2) pa[rt1] = rt2, ans.emplace_back(u, v);
        }
    }
    for (auto i : ans) printf("%d %d\n", i.first, i.second);
    return 0;
}
/*
5 5
1 2
2 3
3 5
4 3
1 5
*/