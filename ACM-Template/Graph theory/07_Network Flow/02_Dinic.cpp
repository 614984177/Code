
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, cap, flow;       //起点,终点,容量,流量
    Edge(int u, int v, int c, int f) : from(u), to(v), cap(c), flow(f) {}
};
struct Dinic
{
    int n, m, s, t;                //结点数,边数(包括反向弧),源点s,汇点t
    vector<Edge> edges;            //边表。edges[e]和edges[e^1]互为反向弧
    vector<int> G[MAXN];           //邻接表，G[i][j]表示结点i的第j条边在edges数组中的序号
    int d[MAXN];                   //从起点到i的距离（层数差）
    int cur[MAXN];                 //当前弧下标
    bool vis[MAXN];                //BFS分层使用
 
    void init(int n)
    {
        this->n = n;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }
 
    void AddEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
 
    bool BFS()//构造分层网络
    {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        d[s] = 0;
        vis[s] = true;
        Q.push(s);
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < G[x].size(); i++)
            {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow)
                {
                    vis[e.to] = true;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
 
    int DFS(int x, int a)//沿阻塞流增广
    {
        if (x == t || a == 0) return a;
        int flow = 0, f;
        for (int& i = cur[x]; i < G[x].size(); i++)//从上次考虑的弧
        {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0)//多路增广
            {
                e.flow += f;
                edges[G[x][i]^1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }
 
    int MaxFlow(int s, int t)
    {
        this->s = s; this->t = t;
        int flow = 0;
        while (BFS())
        {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
 
}solve;