//堆优化，时间复杂度m*logn
const int MAXN = "Edit";
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
struct Edge
{
    int from, to; LL dist;
    Edge() {}
    Edge(int from, int to, LL dist) : from(from), to(to), dist(dist) {}
};
struct Dijkstra
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[MAXN]; // 每个节点出发的边编号（从0开始编号）
    bool done[MAXN];     // 是否已永久标号
    LL d[MAXN];         // s到各点的距离
    int p[MAXN];         // p[i]表示最短路径树中到达i点的边的编号

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();                             // 清空边表
        for (int i = 0; i <= n; i++) G[i].clear(); // 清空邻接表
    }

    void AddEdge(int from, int to, LL dist) // 如果是无向图，每条无向边需调用两次AddEdge
    {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    struct HeapNode
    {
        int from; LL dist;
        HeapNode (int from, LL dist) : from(from), dist(dist) {}
        bool operator < (const HeapNode& rhs) const
        {
            return dist > rhs.dist;
        }
    };

    void dijkstra(int s)
    {
        priority_queue<HeapNode> Q;
        memset(d, INF, sizeof(d));
        memset(done, 0, sizeof(done));
        d[s] = 0;
        Q.push(HeapNode(s, 0));
        while (!Q.empty())
        {
            HeapNode x = Q.top(); Q.pop();
            int u = x.from;
            if (done[u]) continue;
            done[u] = true;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    Q.push(HeapNode(e.to, d[e.to]));
                }
            }
        }
    }

}gao;



//dijkstra,时间复杂度n^2
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int u, int v, int w) : from(u), to(v), dist(w) {}
};
struct Dijkstra
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[MAXN]; // 每个节点出发的边编号（从0开始编号）
    bool done[MAXN];     // 是否已永久标号
    int d[MAXN];         // s到各点的距离
    int p[MAXN];         // p[i]表示最短路径树中到达i点的边的编号

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();                            // 清空边表
        for (int i = 0; i <= n; i++) G[i].clear(); // 清空邻接表
    }

    void AddEdge(int from, int to, int dist)
    { // 如果是无向图，每条无向边需调用两次AddEdge
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    void dijkstra(int s)
    { // 注意此种写法编号从0开始
        memset(d, INF, sizeof(d));
        memset(done, 0, sizeof(done));
        d[s] = 0;
        for (int i = 0; i < n; i++)
        {
            int pos, MIN = INF;
            for (int j = 0; j < n; j++)
            {
                if(!done[j] && d[j] < MIN) MIN = d[pos = j];
            }
            done[pos] = true;
            for (int i = 0; i < G[pos].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (d[e.to] > d[pos] + e.dist)
                {
                    d[e.to] = d[pos] + e.dist;
                    p[e.to] = G[u][i];
                }
            }
        }
    }

}gao;
