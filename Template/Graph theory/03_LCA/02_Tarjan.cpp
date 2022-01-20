// ---
// Tarjan离线算法\\
// 时间复杂度$O(n+q)$
// ---
const int MAXN = "Edit";
struct Edge
{
    int from, to, dist;
    Edge (int u, int v, int w): from(u), to(v), dist(w) {}
};
struct Query
{
    int id, a, b;
    Query (int id, int a, int b): id(id), a(a), b(b) {}
};
struct LCA
{
    int n, m, Q_cnt;
    int f[MAXN];                          //并查集
    vector<Edge> edges;
    vector<int> G[MAXN];
    vector<Query> querys;                 //查询建图
    vector<int> Q[MAXN];                  //查询的邻接表
    bool vis[MAXN];                       //是否被遍历
    int lca[MAXN];                        //答案
    int d[MAXN];                          //到根节点的距离

    void init (int n)
    {
        this->n = n, m = 0, Q_cnt = 0;
        edges.clear(), querys.clear();
        for (int i = 0; i <= n; i++)
        {
            G[i].clear(), Q[i].clear();
            f[i] = i;
            d[i] = vis[i] = 0;
        }
    }

    void AddEdge (int from, int to, int dist)
    {
        edges.emplace_back(from, to, dist);
        edges.emplace_back(to, from, dist);
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    void AddQuery (int id, int u, int v)
    {
        querys.emplace_back(id, u, v);
        querys.emplace_back(id, v, u);
        Q_cnt = querys.size();
        Q[u].push_back(Q_cnt-2);
        Q[v].push_back(Q_cnt-1);
    }

    int Find (int x) { return x == f[x] ? x : f[x] = Find(f[x]); }

    void unite (int x, int y)
    {
        int rt1 = Find(x), rt2 = Find(y);
        if (rt1 != rt2) f[rt2] = rt1;
    }

    void tarjan(int u)
    {
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge& e = edges[G[u][i]];
            int v = e.to;
            if (vis[v]) continue;
            d[v] = d[u] + e.dist;
            tarjan(v);
            unite(u, v);
        }
        for (int i = 0; i < Q[u].size(); i++)
        {
            Query& q = querys[Q[u][i]];
            if (!vis[q.b]) continue;
            lca[q.id] = Find(q.b);
        }
    }

}gao;
