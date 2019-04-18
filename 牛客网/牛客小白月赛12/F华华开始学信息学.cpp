#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
struct BIT
{
    int n; LL a[MAXN];

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

    LL sum(int x)
    {
        LL res = 0;
        while (x)
        {
            res += a[x];
            x -= lowbit(x);
        }
        return res;
    }
    LL sum (int L, int R) { return sum(R) - sum(L - 1); }

}gao;

int n, m, block;
LL lazy[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    gao.init(n);
    int block = sqrt(n);
    while (m--)
    {
        int op, a, b; scanf("%d%d%d", &op, &a, &b);
        if (op == 1)
        {
            if (a > block)
                for (int i = a; i <= n; i += a) gao.update(i, b);
            else lazy[a] += b;
        }
        if (op == 2)
        {
            LL ans = gao.sum(a, b);
            for (int i = 1; i <= block; i++)
                ans += (b/i - (a - 1) / i) * lazy[i];
            printf("%lld\n", ans);
        }
    }
    return 0;
}
/*
10 6
1 1 1
2 4 6
1 3 2
2 5 7
1 6 10
2 1 10
*/