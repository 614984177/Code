#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
//堆优化，时间复杂度m*logn
const LL INF = 0x3f3f3f3f3f3f3f3f;
struct Edge
{
    int from, to; LL dist; bool type;
    Edge() {}
    Edge(int from, int to, LL dist, bool type) : from(from), to(to), dist(dist), type(type) {}
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

    void AddEdge(int from, int to, LL dist, bool type)
    { // 如果是无向图，每条无向边需调用两次AddEdge
        edges.push_back(Edge(from, to, dist, type));
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
                if (d[e.to] == d[u] + e.dist)
                {
                    Edge& tmp = edges[p[e.to]];
                    if (tmp.type == 1) p[e.to] = G[u][i];
                }
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

int n, m, k;
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    while (m--)
    {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        gao.AddEdge(u, v, w, 0);
        gao.AddEdge(v, u, w, 0);
    }
    for (int u = 1; u <= k; u++)
    {
        int v, w; scanf("%d%d", &v, &w);
        gao.AddEdge(1, v, w, 1);
        gao.AddEdge(v, 1, w, 1);
    }
    gao.dijkstra(1);
    int cnt = 0;
    for (int i = 1; i <= n; i++) 
        if (gao.edges[gao.p[i]].type == 1) cnt++;
    printf("%d\n", k - cnt);
    return 0;
}
/*
5 5 3
1 2 1
2 3 2
1 3 3
3 4 4
1 5 5
3 5
4 5
5 5
*/