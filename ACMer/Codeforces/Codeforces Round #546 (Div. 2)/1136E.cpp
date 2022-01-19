#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;

const int MaxNode = MAXN * 4;
struct Node
{
    LL sumv, setv;
    Node () { sumv = 0; setv = INF; }
};
struct SegmentTree
{
    Node a[MaxNode];

    void maintain(int o, int L, int R)
    {
        int lc = o*2, rc = o*2+1;
        if (R > L) a[o].sumv = a[lc].sumv + a[rc].sumv;
        if (a[o].setv != INF) a[o].sumv = a[o].setv * (R-L+1);
    }

    void build(int o, int L, int R, LL* v)
    {
        if (L == R)
        {
            a[o].sumv = v[L];
            return ;
        }
        int M = (L + R) / 2;
        build(o*2, L, M, v);
        build(o*2+1, M+1, R, v);
        maintain(o, L, R);
    }

    void pushdown(int o)
    {
        int lc = o*2, rc= o*2+1;
        if (a[o].setv != INF)
        {
            a[lc].setv = a[rc].setv = a[o].setv;
            a[o].setv = INF;
        }
    }   

    void update(int o, int L, int R, int ql, int qr, LL v)
    {
        if (ql <= L && R <= qr) a[o].setv = v;
        else
        {
            pushdown(o);
            int M = (L + R) / 2;
            int lc = o*2, rc = o*2+1;
            if (ql <= M) update(lc, L, M, ql, qr, v); else maintain(lc, L, M);
            if (qr > M) update(rc, M+1, R, ql, qr, v); else maintain(rc, M+1, R);
        }
        maintain(o, L, R);
    }

    LL query(int o, int L, int R, int ql, int qr)
    {
        if (a[o].setv != INF)
            return a[o].setv * (min(qr, R) - max(ql, L) + 1);
        if (ql <= L && R <= qr)
            return a[o].sumv;
        LL ans = 0;
        int M = (L + R) / 2;
        if (ql <= M) ans += query(o*2, L, M, ql, qr);
        if (qr > M) ans += query(o*2+1, M+1, R, ql, qr);
        return ans;
    }

};


int n, a[MAXN];
LL t[MAXN], sum[MAXN], b[MAXN];
SegmentTree B;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    b[1] = a[1];
    for (int i = 2; i <= n; i++)
    {
        int k; scanf("%d", &k);
        t[i] = t[i - 1] + k;
        sum[i] = sum[i - 1] + t[i];
        b[i] = a[i] - t[i];
    }
    B.build(1, 1, n, b);
    int Q; scanf("%d", &Q);
    while (Q--)
    {
        char op; int x, y; scanf(" %c%d%d", &op, &x, &y);
        if (op == 's') printf("%lld\n", B.query(1, 1, n, x, y) + sum[y] - sum[x - 1]);
        else 
        {
            LL v = y + B.query(1, 1, n, x, x);
            int L = x, R = n + 1;
            while (L < R)
            {
                int M = (L + R) / 2;
                if (B.query(1, 1, n, M, M) <= v) L = M + 1;
                else R = M;
            }
            B.update(1, 1, n, x, L - 1, v);
        }
    }
    return 0;
}
/*
3
1 2 3
1 -1
5
s 2 3
+ 1 2
s 1 2
+ 3 1
s 2 3
*/