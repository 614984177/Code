#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;

double pos[MAXN * 2];
struct SegementTree
{
    struct Node
    {
        double cnt;
        int add;
        Node () {}
        Node (double cnt, int add) : cnt(cnt), add(add) {}
    };
    Node a[MAXN*2*4];

    void maintain(int o, int L, int R)
    {
        int lc = o * 2, rc = o * 2 + 1;
        a[o].cnt=0;
        if (L < R)
            a[o].cnt = a[lc].cnt + a[rc].cnt;
        if (a[o].add) a[o].cnt = pos[R + 1] - pos[L];
    }

    void build(int o, int L, int R)
    {
        a[o] = Node(0.0, 0);
        if (L == R) return ;
        int M = (L + R) / 2;
        build(o * 2, L, M);
        build(o * 2 + 1, M + 1, R);
        maintain(o, L, R);
    }

    void update(int o, int L, int R, int qL, int qR, int v)
    {
        if (qL <= L && R <= qR)
        {
            a[o].add += v;
            maintain(o, L, R);
            return ;
        }
        int M = (L + R) / 2;
        if (qL <= M) update(o * 2, L, M, qL, qR, v);
        if (qR > M) update(o * 2 + 1, M + 1, R, qL, qR, v);
        maintain(o, L, R);
    }

    double query(int o, int L, int R, int qL, int qR)
    {
        if (a[o].add) return min(R, qR) - max(L, qL) + 1;
        if (qL <= L && R <= qR) return a[o].cnt;
        double ans = 0;
        int M = (L + R) / 2;
        if (qL <= M) ans += query(o * 2, L, M, qL, qR);
        if (qR > M) ans += query(o * 2 + 1, M + 1, R, qL, qR);
        return ans;
    }

};

SegementTree gao;
int n;
struct Segement
{
    double l, r, h;
    int flag;
    Segement () {}
    Segement (double l, double r, double h, int flag) : l(l), r(r), h(h), flag(flag) {}
};
Segement a[MAXN * 2];
int main()
{
    int kase = 0;
    while (~scanf("%d", &n) && n)
    {
        for (int i = 0; i < n; i++)
        {
            double x1, y1, x2, y2; scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
            pos[i * 2] = x1;
            pos[i * 2 + 1] = x2;
            a[i * 2] = Segement(x1, x2, y1, 1);
            a[i * 2 + 1] = Segement(x1, x2, y2, -1);
        }
        n *= 2;
        pos[n] = -1;
        sort(pos, pos + n + 1);
        int m = unique(pos, pos + n + 1) - pos - 1;
        sort(a, a + n, [](const Segement &a, const Segement &b){
            return a.h < b.h;
        });
        double ans = 0;
        gao.build(1, 1, m);
        for (int i = 0; i < n - 1; i++)
        {
            int L = lower_bound(pos + 1, pos + m, a[i].l) - pos;
            int R = lower_bound(pos + 1, pos + m, a[i].r) - pos;
            gao.update(1, 1, m, L, R - 1, a[i].flag);
            ans += (a[i + 1].h - a[i].h) * gao.a[1].cnt;
        }
        printf("Test case #%d\n", ++kase);
        printf("Total explored area: %.2f\n\n", ans);
    }
    return 0;
}
/*
2
10 10 20 20
15 15 25 25.5
0
*/