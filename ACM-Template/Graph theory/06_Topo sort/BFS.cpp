//
const int MAXN = "Edit";
struct Edge
{
    int from, to;
    Edge() {}
    Edge(int from, int to) : from(from), to(to) {}
};
struct TopoSort
{
    int n, m, t, indegree[MAXN], topo[MAXN];
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

    bool toposort()
    {
        t = 1;
        memset(indegree, 0, sizeof(indegree));
        for (int i = 0; i < m; i++) 
        {
            auto& e = edges[i];
            indegree[e.to]++;
        } 
        queue<int> Q;
        for (int i = 1; i <= n; i++)
            if (!indegree[i]) Q.push(i);
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            topo[t++] = u;
            for (int i = 0; i < G[u].size(); i++)
            {
                int v = G[u][i];
                if (--indegree[v] == 0) Q.push(v);
            }
        }
        for (int i = 1; i <= n; i++) 
            if (indegree[i]) return false;
        return true;
    }

};

int main()
{
    while (~scanf("%d%d", &n, &m) && (n+m))
    {
        memset(indegree, 0, sizeof(indegree));
        memset(G, 0, sizeof(G));
        for (int i = 0; i < m; i++)
        {
            int u, v; scanf("%d%d", &u, &v);
            G[u][v] = 1;
            indegree[v]++;
        }
        toposort(topo);
        for (int i = 0; i < topo.size(); i++)
        {
            printf("%d", topo[i]);
            if (i != topo.size()-1) printf(" ");
            else printf("\n");
        }
    }
    return 0;
}
/*
5 4
1 2
2 3
1 3
1 5
0 0
*/