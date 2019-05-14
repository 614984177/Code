#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long LL;
int n, a[MAXN];
vector<pair<LL, int>> get_f(LL x)
{
    vector<pair<LL, int>> v;
    for (int i = 2; 1LL * i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0) cnt++, x /= i;
            v.emplace_back(i, cnt);
        }
    }
    if (x > 1) v.emplace_back(x, 1);
    return v;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        LL ans = 1LL * a[1] * a[n];
        for (int i = 1; i <= (n + 1) / 2; i++)
            if (1LL * a[i] * a[n - i + 1] != ans) { ans = -1; break; }
        vector<pair<LL, int>> v = get_f(ans);
        LL t = 1;
        for (auto i : v) t *= (1 + i.second);
        if (t - 2 != 1LL * n) ans = -1;
        printf("%lld\n", ans);
    }
    return 0;
}
/*
20
8
8 2 12 6 4 24 16 3
1
2
*/