//复杂度m*logm
const int MAXN = "Edit";
struct Edge
{
    int from, to, dist;       //起点,终点,边权
    Edge () {}
    Edge(int u, int v, int w) : from(u), to(v), dist(w) {}
};
struct Kruskal
{
    int n, m;            //点数,边数
    vector<Edge> edges;  //边表
    int f[MAXN];         //并查集的父亲数组
    vector<int> res;     //生成树中的边的编号

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear(), res.clear();
        for (int i = 0; i <= n; i++) f[i] = i;
    }

    void AddEdge(int from, int to, int dist)
    {
        edges.push_back(Edge(from, to, dist));
        m = edges.size();
    }

    int Find(int x) { return f[x] == x ? x : f[x] = Find(f[x]); } //并查集的Find

    int kruskal()
    {
        int ans = 0;
        sort(edges.begin(), edges.end(),
             [](const Edge& a, const Edge& b){ return a.dist < b.dist; });
        for (int i = 0; i < m; i++)
        {
            Edge& e = edges[i];
            int root1 = Find(e.from), root2 = Find(e.to);
            if (root1 != root2)
            {
                f[root1] = root2;
                ans += e.dist;
                res.push_back(i);
                if (res.size() == n - 1) break;
            }
        }
        return ans;
    }

}gao;