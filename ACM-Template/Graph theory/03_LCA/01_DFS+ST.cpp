// ---
// DFS+ST在线算法\\
// 时间复杂度$O(nlogn+q)$
// ---
const int MAXN = "Edit";
struct Edge
{
    int from, to, dist;
    Edge (int u, int v, int w): from(u), to(v), dist(w) {}
};
struct LCA
{
    int n, m;                 // 点数和边数
    vector<Edge> edges;       // 边列表
    vector<int> G[MAXN];      // 每个节点出发的边编号（从0开始编号）
    vector<int> sp;           // dfs序
    int dfn[MAXN];            // 第一次出现时间
    pair<int, int> dp[21][MAXN << 1];
    int d[MAXN];              //到根节点的距离

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear(), sp.clear();
        for (int i = 0; i <= n; i++) G[i].clear(), d[i] = 0;
        sp.clear();
    }

    void AddEdge (int from, int to, int dist)
    {
        edges.emplace_back(from, to, dist);
        edges.emplace_back(to, from, dist);
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    void dfs(int u, int fa)
    {
        dfn[u] = sp.size();
        sp.push_back(u);
        for (auto& id : G[u])
        {
            Edge& e = edges[id];
            int v = e.to;
            if (v == fa) continue;
            d[v] = d[u] + e.dist;
            dfs(v, u);
            sp.push_back(u);
        }
    }

    void initrmq()
    {
        int len = sp.size();
        for (int i = 0; i < len; i++) dp[0][i] = {dfn[sp[i]], sp[i]};
        for (int i = 1; (1 << i) <= len; i++)
            for (int j = 0; j + (1 << i) - 1 < len; j++)
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][j + (1 << (i - 1))]);
    }

    int lca(int u, int v)
    {
        int l = dfn[u], r = dfn[v];
        if (l > r) swap(l, r);
        int k = 31 - __builtin_clz(r - l + 1);
        return min(dp[k][l], dp[k][r - (1 << k) + 1]).second;
    }

}gao;
