//点双连通分量，割点的bccno无意义
const int MAXN = "Edit";
struct Edge
{
    int from, to;
    Edge (int u, int v): from(u), to(v) {}
};
struct VertexBCC//点双连通分量
{//有无重边无影响
    int n, m;
    int DFN[MAXN], iscut[MAXN], bccno[MAXN], dfs_clock, bcc_cnt;
    vector<Edge> edges;
    vector<int> G[MAXN], bcc[MAXN];
    stack<Edge> S;

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();
        for (int i = 0; i < n; i++) G[i].clear();
    }

    void AddEdge (int from, int to)
    {
        edges.push_back(Edge(from, to));
        edges.push_back(Edge(to, from));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    int dfs(int u, int fa)
    {
        int lowu = DFN[u] = ++dfs_clock;
        int child = 0;
        bool flag = false;
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge e = edges[G[u][i]];
            int v = e.to;
            if (!DFN[v])//没有访问过v
            {
                S.push(e);
                child++;
                int lowv = dfs(v, u);
                lowu = min(lowu, lowv); //用后代的low函数更新自己
                if (lowv >= DFN[u])
                {
                    iscut[u] = true;
                    bcc_cnt++;
                    bcc[bcc_cnt].clear(); //注意！bcc从1开始编号
                    while (1)
                    {
                        Edge x = S.top(); S.pop();
                        if (bccno[x.from] != bcc_cnt)
                            bcc[bcc_cnt].push_back(x.from), bccno[x.from] = bcc_cnt;
                        if (bccno[x.to] != bcc_cnt)
                            bcc[bcc_cnt].push_back(x.to), bccno[x.to] = bcc_cnt;
                        if (x.from == u && x.to == v) break;
                    }
                }
            }
            else if (DFN[v] < DFN[u] && v != fa)
            {
                S.push(e);
                lowu = min(lowu, DFN[v]); //用返祖边更新自己
            }
        }
        if (fa < 0 && child == 1) iscut[u] = 0;
        return lowu;
    }

    void find_bcc()
    {
        //注意点的编号从0开始
        //调用结束后s保证为空，所以不用清空
        memset(DFN, 0, sizeof(DFN));
        memset(iscut, 0, sizeof(iscut));
        memset(bccno, 0, sizeof(bccno));
        dfs_clock = bcc_cnt = 0;
        for (int i = 0; i < n; i++)
            if (!DFN[i]) dfs(i, -1);
    }

}gao;




//边双连通分量
const int MAXN = "Edit";
const int MAXM = "Edit";
struct Edge
{
    int from, to;
    Edge (int u, int v): from(u), to(v) {}
};
struct EdgeBCC //边双连通分量
{
	//有重边也算桥的时候，记得先去重再加边！！！
    int n, m;
    int LOW[MAXN], DFN[MAXN], bccno[MAXN], dfs_clock, bcc_cnt;
    bool isbridge[MAXM];
    vector<Edge> edges, bridge;
    vector<int> G[MAXN];

    void init(int n)
    {
        this->n = n, m = 0;
        edges.clear();
        for (int i = 0; i <= n; i++) G[i].clear();
    }

    void AddEdge (int from, int to) 
    { 
        edges.push_back(Edge(from, to));
        edges.push_back(Edge(to, from));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }

    void dfs(int u, int fa)
    {
        LOW[u] = DFN[u] = ++dfs_clock;
        bool flag = false;
        for (int i = 0; i < G[u].size(); i++)
        {
            Edge& e = edges[G[u][i]];
            int v = e.to;
            if (v == fa && !flag) { flag = true; continue; }
            if (!DFN[v]) //没有访问过v
            {
                dfs(v, u);
                LOW[u] = min(LOW[u], LOW[v]); //用后代的low函数更新自己
                if (LOW[v] > DFN[u])//桥
                {
                    bridge.push_back(e);
                    isbridge[G[u][i]] = isbridge[G[u][i]^1] = true;
                }
            }
            else if (DFN[v] < DFN[u])
                LOW[u] = min(LOW[u], DFN[v]); //用反向边更新自己
        }
    }

    void dfs2(int u)
    {
        bccno[u] = bcc_cnt;
        for(int i = 0; i < G[u].size(); i++)
        {
            Edge& e = edges[G[u][i]];
            if(!isbridge[G[u][i]] && !bccno[e.to])
                dfs2(e.to);
        }
    }

    void find_bcc()
    { // 点的编号从0开始
        memset(DFN, 0, sizeof(DFN)), memset(LOW, 0, sizeof(LOW));
        bridge.clear(), memset(bccno, 0, sizeof(bccno));
        dfs_clock = bcc_cnt = 0;
        for (int i = 1; i <= n; i++)
            if (!DFN[i]) dfs(i, 0);
        for (int i = 1; i <= n; i++)
            if(!bccno[i]) bcc_cnt++, dfs2(i);
    }

}gao;
