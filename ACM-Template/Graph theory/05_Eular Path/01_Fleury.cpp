// ---
// 若有两个点的度数是奇数，则此时这两个点只能作为欧拉路径的起点和终点。
// ---
const int MAXN = "Edit";
const int MAXM = "Edit"
struct Edge
{
    int from, to;       //起点,终点
    Edge(int from, int to) : from(from), to(to) {}
};
struct EulerianPath
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[MAXN];
    int indeg[MAXN], outdeg[MAXN];
    bool vis[MAXM];
    vector<int> ans;

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear(), ans.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i <= n; i++) indeg[i] = outdeg[i] = 0;
        memset(vis, 0, sizeof(vis));
    }

    void AddEdge(int from, int to)
    {
        outdeg[from]++, indeg[to]++;
        edges.push_back(Edge(from, to));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    void Fleury(int u)
    {
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge& e = edges[G[u][i]];
            if (!vis[G[u][i]])
            {
                vis[G[u][i]] = true;
                Fleury(e.to);
                ans.push_back(G[u][i]);
            }
        }
    }

    bool eulerianpath()
    {//注意点编号从0开始
        s = t = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (abs(outdeg[i] - indeg[i]) >= 2) return false;
            if (outdeg[i] == indeg[i] + 1) s = i, cnt++;
            if (outdeg[i] == indeg[i] - 1) t = i, cnt++;
            if (s == -1 && outdeg[i] == indeg[i] && outdeg[i]) s = t = i;
        }
        if (cnt > 2 || s == -1 || t == -1) return false;
        Fleury(s);
        if (ans.size() == m) return true;
        return false;
    }

}gao;