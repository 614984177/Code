//时间复杂度O(v*E*E)
const int MAXN = "Edit";
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, cap, flow;    //起点,终点,容量,流量
    Edge () {}
    Edge(int u, int v, int c, int f):from(u), to(v), cap(c), flow(f){}
};
struct EdmondsKarp
{
    int n, m;                   //n个点,m条边
    vector<Edge> edges;         //边数的两倍
    vector<int> G[MAXN];        //邻接表,G[i][j]表示节点i的第j条边在edges数组中的序号
    int a[MAXN];                //当起点到i的可改进量
    int p[MAXN];                //最短路树上p的入弧编号
 
    void init(int n)
    {
        this->n = n;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }
 
    void AddEdge(int from, int to, int cap)
    {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));//反向弧
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
 
    int MaxFlow(int s, int t)
    {
        int flow = 0;
        while (true)
        {
            memset(a, 0, sizeof(a));
            queue<int> Q;
            a[s] = INF;
            Q.push(s);
            while (!Q.empty())
            {
                int x = Q.front(); Q.pop();
                for (int i = 0; i < G[x].size(); i++)
                {
                    Edge& e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x], e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if (a[t]) break;
            }
            if (!a[t]) break;
            for (int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
                edges[p[u]^1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
 
}solve;
