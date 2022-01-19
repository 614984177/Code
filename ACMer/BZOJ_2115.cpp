#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
typedef long long LL;

struct LineBase
{
    LL a[61];
    LineBase () { memset(a, 0, sizeof(a)); }
    bool insert(LL v)
    {
        for (int i = 60; i >= 0; i--)
        {
            if (v & (1LL << i))
            {
                if (!a[i]) { a[i] = v; break; }
                v ^= a[i];
            }
        }
        return v > 0;
    }   
    LL MAX(LL x)
    {
        LL res = x;
        for (int i = 60; i >= 0; i--)
            if ((res^a[i]) > res) res ^= a[i];
        return res;
    }
}LB;

int n, m, cnt;
LL d[MAXN], loop[MAXN * 10]; // 注意n=1,m=1e5的时候,即所有边都是自环
vector<pair<int, LL> > G[MAXN]; 
bool vis[MAXN];
void dfs(int u)
{
    vis[u] = true;
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].first; LL w = G[u][i].second;
        if (!vis[v]) d[v] = d[u] ^ w, dfs(v);
        else loop[++cnt] = d[u] ^ w ^ d[v];
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
        G[u].push_back(make_pair(v, w));
        G[v].push_back(make_pair(u, w));
    }
    dfs(1);
    //线性基
    for (int i = 1; i <= cnt; i++) LB.insert(loop[i]);
    printf("%lld\n", LB.MAX(d[n]));
    return 0;
}
/*
5 7 
1 2 2 
1 3 2 
2 4 1 
2 5 1 
4 5 3 
5 3 4 
4 3 2 
*/