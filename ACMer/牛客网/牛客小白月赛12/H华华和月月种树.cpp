#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
struct BIT
{
    int n; int a[MAXN];

    void init(int n)
    {
        this->n = n; 
        memset(a, 0, sizeof(a));
    }

    int lowbit(int x) { return x & -x; }

    void update(int x, int v)
    {
        while (x <= n)
        {
            a[x] += v;
            x += lowbit(x);
        }
    }

    int sum(int x)
    {
        int res = 0;
        while (x)
        {
            res += a[x];
            x -= lowbit(x);
        }
        return res;
    }
    int sum(int L, int R) { return sum(R) - sum(L - 1); }

}gao;

struct Query
{
    int op, id, v;
};
Query q[MAXN];
int n, m, DFN[MAXN], dfs_clock, sz[MAXN];
vector<int> G[MAXN];
void dfs(int u)
{
    sz[u] = 1;
    DFN[u] = ++dfs_clock;
    for (auto v : G[u])
    {
        dfs(v);
        sz[u] += sz[v];
    }
}

int main()
{
    scanf("%d", &m);
    n = 1;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d%d", &q[i].op, &q[i].id); q[i].id++;
        if (q[i].op == 2) scanf("%d", &q[i].v);
        if (q[i].op == 1) 
        {
            G[q[i].id].push_back(++n);
            q[i].id = n;
        }
    }
    dfs(1);
    gao.init(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int id = q[i].id;
        if (q[i].op == 1)
        {
            int v = gao.sum(DFN[id]);
            gao.update(DFN[id], -v);
            gao.update(DFN[id] + 1, v);
        }
        if (q[i].op == 2) 
        {
            int v = q[i].v;
            gao.update(DFN[id], v);
            gao.update(DFN[id] + sz[id], -v);
        }
        if (q[i].op == 3) printf("%d\n", gao.sum(DFN[id]));
    }
    return 0;
}
/*
9
1 0
2 0 1
3 0
3 1
1 0
1 1
2 0 2
3 1
3 3
*/