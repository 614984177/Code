#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long LL;
const int MAXN = 1e5 + 5;
struct LineBase
{
    LL b[MAXN], q[MAXN];
    int cnt;

    LineBase ()
    {
        cnt = 0;
        memset(b, 0, sizeof(b));
        memset(q, 0, sizeof(q));
    }

    bool insert (LL x)
    {
        for (int i = 60; i >= 0; i--)
        {
            if (x & (1LL<<i))
            {
                if (!b[i]) { b[i] = x; break; }
                x ^= b[i];
            }
        }
        return x > 0;
    }

    LL MAX()
    {
        LL res = 0;
        for (int i = 60; i >= 0; i--)
            if ((res^b[i]) > res) res ^= b[i];
        return res;
    }

    LL MIN()
    {
        for (int i = 60; i >= 0; i--)
            if (b[i]) return b[i];
        return 0;
    }

    void rbuild()
    {
        for (int i = 60; i >= 0; i--)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (b[i] & (1LL<<j)) b[i] ^= b[j];
            }
        }
        for (int i = 0; i <= 60; i++)
            if (b[i]) q[cnt++] = b[i];
    }

    LL kth(LL k) // k小值
    {
        LL res = 0;
        if (k >= (1LL << cnt)) return -1;
        for (int i = 60; i >= 0; i--)
            if (k & (1LL << i)) res ^= q[i];
        return res;
    }
    
}LB;


int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%lld%d", &a[i].X, &a[i].Y);
    sort(a, a + n, cmp);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (LB.insert(a[i].X)) ans += a[i].Y;
    printf("%d\n", ans);
    return 0;
}
/*
3 
1 10 
2 20 
3 30 
*/