#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, m, k, MAX[MAXN];
LL a[MAXN], dp[MAXN];
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= k; i++) a[i] += a[i - 1], dp[i] = a[i];
    while (m--)
    {
        int x, y; scanf("%d%d", &x, &y);
        MAX[x] = max(MAX[x], y);
    }
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = min(dp[i], dp[i - j] + a[i] - a[i - j + MAX[j]]); 
        }
    }
    printf("%lld\n", dp[k]);
    return 0;
}
/*
7 4 5
2 5 4 2 6 3 1
2 1
6 5
2 1
3 1
*/