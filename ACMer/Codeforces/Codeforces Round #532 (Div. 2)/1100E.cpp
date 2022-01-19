#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
//
struct Edge
{
    int from, to, w;
    Edge() {}
    Edge(int from, int to, int w) : from(from), to(to), w(w) {}
};
struct Toposort
{
    int n, m, t, c[MAXN], topo[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];
    int limit;

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }

    void AddEdge(int from, int to, int w)
    {
        edges.push_back(Edge(from, to, w));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    bool dfs(int u)
    {
        c[u] = -1;//访问标志
        for (auto& i : G[u])
        {
            Edge& e = edges[i];
            if (e.w <= limit) continue;
            if (c[e.to] < 0) return false;//存在有向环，失败退出
            else if (!c[e.to] && !dfs(e.to)) return false;
        }
        c[u] = 1; topo[t--] = u;
        return true;
    }

    bool toposort(int limit)
    {
        this->limit = limit;
        t = n;
        memset(c, 0, sizeof(c));
        for (int u = 1; u <= n; u++)
        {
            if (c[u]) continue;
            if (!dfs(u)) return false;
        }
        return true;
    }

}gao;

int n, m, pos[MAXN];
bool check(int x)
{
    return gao.toposort(x);
}
int main()
{
    scanf("%d%d", &n, &m);
    gao.init(n);
    while (m--)
    {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        gao.AddEdge(u, v, w);
    }
    int L = 0, R = (int)1e9 + 1;
    while (L < R)
    {
        int M = L + (R - L) / 2;
        if (check(M)) R = M;
        else L = M + 1;
    }
    check(L);
    for (int i = 1; i <= n; i++) pos[gao.topo[i]] = i;
    vector<int> ans;
    for (int i = 0; i < gao.edges.size(); i++)
    {
        auto& e = gao.edges[i];
        if (e.w <= L && pos[e.from] >= pos[e.to]) ans.push_back(i);
    }
    printf("%d %d\n", L, ans.size());
    for (auto& i: ans) printf("%d ", i + 1);
    return 0;
}
/*
5 6
2 1 1
5 2 6
2 3 2
3 4 3
4 5 5
1 5 4
*/