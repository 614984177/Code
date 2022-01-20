//堆优化的prime，复杂度为m*logn
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, dist;       //起点,终点,边权
    Edge () {}
    Edge(int u, int v, int d) : from(u), to(v), dist(d) {}
};
struct Prim
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[MAXN]; // 每个节点出发的边编号（从0开始编号）
    bool done[MAXN];     // 是否已永久标号
    int d[MAXN];         // 各点到当前生成树的距离
    int p[MAXN];         // p[i]表示最小生成树中到达i点的边的编号
    vector<int> res;     // 最小生成树中的边的编号

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear(), res.clear();                
        for (int i = 0; i <= n; i++) G[i].clear(); // 清空邻接表
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge(from, to, dist));
        edges.push_back(Edge(to, from, dist));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    struct HeapNode
    {
        int from, dist;
        HeapNode (int u, int d) : from(u), dist(d) {}
        bool operator < (const HeapNode& rhs) const
        {
            return dist > rhs.dist;
        }
    };

    int prim(int s)
    {
        int ans = 0;
        priority_queue<HeapNode> Q;
        memset(d, INF, sizeof(d));
        d[s] = 0;
        memset(done, 0, sizeof(done));
        Q.push(HeapNode(s, 0));
        while (!Q.empty())
        {
            HeapNode x = Q.top(); Q.pop();
            int u = x.from;
            if (done[u]) continue;
            done[u] = true;
            ans += d[u];
            res.push_back(p[u]);
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (d[e.to] > e.dist)
                {
                    d[e.to] = e.dist;
                    p[e.to] = G[u][i];
                    Q.push(HeapNode(e.to, d[e.to]));
                }
            }
        }
        return ans;
    }

}gao;



//prim，时间复杂度为n^2
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int w) : from(u), to(v), dist(w) {}
};
struct Prim
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[MAXN]; // 每个节点出发的边编号（从0开始编号）
    bool done[MAXN];     // 是否已永久标号
    int d[MAXN];         // s到各点的距离
    int p[MAXN];         // p[i]表示最短路径树中到达i点的边的编号
    vector<int> res;     // 最小生成树中的边的编号

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear(), res.clear();
        for (int i = 0; i <= n; i++) G[i].clear(); 
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge(from, to, dist));
        edges.push_back(Edge(to, from, dist));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    int prim(int s)
    { // 注意此种写法编号从0开始
        int ans = 0;
        for (int i = 0; i <= n; i++) d[i] = INF;
        d[s] = 0;
        memset(done, 0, sizeof(done));
        for (int i = 0; i < n; i++)
        {
            int pos, MIN = INF;
            for (int j = 0; j < n; j++)
            {
                if(!done[j] && d[j] <= MIN) MIN = d[pos = j];
            }
            done[pos] = true;
            ans += d[pos];
            res.push_back(p[u]);
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (d[e.to] > e.dist)
                {
                    d[e.to] = e.dist;
                    p[e.to] = G[u][i];
                }
            }
        }
        return ans;
    }

}gao;