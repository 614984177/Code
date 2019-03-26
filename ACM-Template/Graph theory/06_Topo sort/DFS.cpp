//
const int MAXN = "Edit";
struct Edge
{
    int from, to;
    Edge() {}
    Edge(int from, int to) : from(from), to(to) {}
};
struct Toposort
{
    int n, m, t, c[MAXN], topo[MAXN];
    vector<Edge> edges;
    vector<int> G[MAXN];
    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }

    void AddEdge(int from, int to)
    {
        edges.push_back(Edge(from, to));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    bool dfs(int u)
    {
        c[u] = -1;//访问标志
        for (int i = 0; i < G[u].szie(); i++)
        {
            Edge& e = edges[i];
            if (c[e.to] < 0) return false;//存在有向环，失败退出
            else if (!c[e.to] && !dfs(e.to)) return false;
        }
        c[u] = 1; topo[t--] = u;
        return true;
    }
    
    bool toposort()
    {
        t = n;
        memset(c, 0, sizeof(c));
        for (int u = 1; u <= n; u++)
        {
            if (c[u]) continue;
            if (!dfs(u)) return false;
        }
        return true;
    }

};
