#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5e5 + 5;
struct LineBase
{
    LL a[61], b[61];
    int cnt;
    int idx[61];

    LineBase ()
    {
        cnt = 0;
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
    }

    bool insert (LL v, int pos)
    {
        for (int i = 60; i >= 0; i--)
        {
            if (v & (1LL<<i))
            {
                if (!a[i]) { a[i] = v; idx[i] = pos; break; }
                if (idx[i] < pos) swap(idx[i], pos), swap(a[i], v);
                v ^= a[i];
            }
        }
        return v > 0;
    }

    LL MAX(int l)
    {
        LL res = 0;
        for (int i = 60; i >= 0; i--)
            if ((res^a[i]) > res && idx[i] >= l) res ^= a[i];
        return res;
    }

    LL MIN()
    {
        for (int i = 60; i >= 0; i--)
            if (a[i]) return a[i];
        return 0;
    }

    void rbuild()
    {
        for (int i = 60; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (a[i] & (1LL<<j)) a[i] ^= a[j];
            }
        }
        for (int i = 0; i <= 60; i++)
            if (a[i]) b[cnt++] = a[i];
    }

    LL kth(LL k) // k小值
    {
        LL res = 0;
        if (k >= (1LL << cnt)) return -1;
        for (int i = 60; i >= 0; i--)
            if (k & (1LL << i)) res ^= b[i];
        return res;
    }


}LB;

struct Query
{
    int l, r, id;
    Query () {}
    Query (int l, int r, int id) : l(l), r(r), id(id) {} 
    bool operator < (const Query& rhs) const
    { 
        if (r != rhs.r) return r < rhs.r;
        return l < rhs.l;
    }
};
int n, q, c[MAXN];
LL ans[MAXN];
Query Q[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    scanf("%d", &q);
    for (int i = 0; i < q; i++) 
    {
        int l, r; scanf("%d%d", &l, &r);
        l--, r--;
        Q[i] = Query(l, r, i);
    }
    sort(Q, Q + q);
    int r = 0;
    for (int i = 0; i < q; i++)
    {
        while (r <= Q[i].r) LB.insert(c[r], r), r++;
        ans[Q[i].id] = LB.MAX(Q[i].l);
    }
    for (int i = 0; i < q; i++) printf("%lld\n", ans[i]);
    return 0;
}
/*
4
7 2 3 4
3
1 4
2 3
1 3
*/