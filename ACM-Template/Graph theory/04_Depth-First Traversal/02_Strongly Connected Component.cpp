const int MAXN = "Edit";
struct Edge
{
    int from, to;
    Edge (int u, int v): from(u), to(v) {}
};
struct SCC
{
    int n, m;
    int DFN[MAXN], LOW[MAXN], sccno[MAXN], dfs_clock, scc_cnt;
    vector<Edge> edges;
    vector<int> G[MAXN];
    stack<int> S;

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }

    void AddEdge (int from, int to)
    { 
        edges.push_back(Edge(from, to));
        m = edges.size();
        G[from].push_back(m-1);
    }

    void dfs(int u)
    {
        DFN[u] = LOW[u] = ++dfs_clock;
        S.push(u);
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge e = edges[G[u][i]];
            int v = e.to;
            if (!DFN[v])
            {
                dfs(v);
                LOW[u] = min(LOW[u], LOW[v]);
            }
            else if (!sccno[v])
                LOW[u] = min(LOW[u], DFN[v]);
        }
        if (LOW[u] == DFN[u])
        {
            scc_cnt++;
            while (1)
            {
                int x = S.top(); S.pop();
                sccno[x] = scc_cnt;
                if (x == u) break;
            }
        }
    }

    void find_scc()
    { // 注意点的编号从0开始
        dfs_clock = scc_cnt  = 0;
        memset(DFN, 0, sizeof(DFN)), memset(sccno, 0, sizeof(sccno));
        for (int i = 0; i < n; i++)
            if (!DFN[i]) dfs(i);
    }

}gao;
