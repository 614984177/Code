  //SPFA（队列优化BellmanFord）,最坏时间复杂度n*m，一般情况比这个好的多
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int from, int to, int dist) : from(from), to(to), dist(dist) {}
};
struct BellmanFord
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[MAXN]; // 每个节点出发的边编号（从0开始编号）
    bool inq[MAXN];      // 是否在队列中
    int d[MAXN];         // s到各个点的距离
    int p[MAXN];         // p[i]表示最短路径树中到达i点的边的编号
    int cnt[MAXN];       // 进队次数

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    bool bellmanford(int s)
    {
        queue<int> Q;
        memset(inq, 0, sizeof(inq));
        memset(cnt, 0, sizeof(cnt));
        memset(d, INF, sizeof(d));
        d[s] = 0; inq[s] = true;
        Q.push(s);
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            inq[u] = false;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if (d[u] < INF && d[e.to] > d[u] + e.dist)
                {
                    d[e.to] = d[u] + e.dist;
                    p[e.to] = G[u][i];
                    if (!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to] = true;
                        if (++cnt[e.to] > n) return false;//有负环
                    }
                }
            }
        }
        return true;//无负环
    }

};

//时间复杂度n*m
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int from, int to, int dist) : from(from), to(to), dist(dist) {}
};
struct BellmanFord
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[MAXN]; // 每个节点出发的边编号（从0开始编号）
    bool inq[MAXN];      // 是否在队列中
    int d[MAXN];         // s到各个点的距离
    int p[MAXN];         // p[i]表示最短路径树中到达i点的边的编号
 
    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    bool bellmanford(int s)//bellmanford
    {
        memset(d, INF, sizeof(d));
        d[s] = 0;
        for (int k = 0; k < n - 1; k++)//迭代n-1次
        {
            bool flag = false;
            for (int i = 0; i < m; i++)//检查每条边
            {
                Edge& e = edges[i];
                if (d[e.from] < INF && d[e.to] > d[e.from] + e.dist)
                {
                    flag = true;
                    d[e.to] = d[e.from] + e.dist;
                    p[e.to] = i;
                }
            }
            if (!flag) break;//只要某一次没relax，说明最短路径已经查找完毕，或者部分点不可达，可以跳出
        }
        for (int i = 0; i < m; i++)
        {
            Edge& e = edges[i];
            if (d[e.from] < INF && d[e.to] > d[e.from] + e.dist) return false;//有负环
        }
        return true;//没有负环
    }

}gao;



//dfs版本的SPFA,好像可以更快一些？
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, dist;
    Edge() {}
    Edge(int from, int to, int dist) : from(from), to(to), dist(dist) {}
};
struct BellmanFord
{
    int n, m;            // 点数和边数
    vector<Edge> edges;  // 边列表
    vector<int> G[MAXN]; // 每个节点出发的边编号（从0开始编号）
    bool vis[MAXN];      // 是否在队列中
    int d[MAXN];         // s到各个点的距离
    int p[MAXN];         // p[i]表示最短路径树中到达i点的边的编号
    bool flag;

    void init(int n)
    {
        flag = false;
        this->n = n, m = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
        G[from].push_back(m - 1);
    }

    void dfs(int u)//spfa
    {
        vis[u] = true;
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge& e = edges[G[u][i]];
            if (d[e.to] > d[u] + e.dist)
            {
                if (vis[e.to]) { flag = true; break ; }
                d[e.to] = d[u] + e.dist;
                p[e.to] = G[u][i];
                dfs(e.to);
            }
        }
        vis[u] = false;
    }

    bool bellmanford(int s)
    {
        memset(d, INF, sizeof(d));
        memset(vis, 0, sizeof(vis));
        d[s] = 0;
        dfs(s);
        if (flag) return false;//有负环
        return true;//无负环
    }
 
}gao;