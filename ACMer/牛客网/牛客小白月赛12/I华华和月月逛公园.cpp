#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

const int MAXM = 6e5 + 5;
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

int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    gao.init(n);
    for (int i = 0; i < m; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        gao.AddEdge(u, v);
    }
    gao.find_bcc();
    printf("%d\n", m - gao.bridge.size());
    return 0;
}
/*
5 5
1 2
2 3
3 4
4 5
3 5
*/