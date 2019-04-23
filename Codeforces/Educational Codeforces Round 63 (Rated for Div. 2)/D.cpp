#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long LL;
int n, a[MAXN], x;
LL dp[MAXN][3];
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = max(0LL, dp[i - 1][0] + a[i]);
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1LL * a[i] * x;
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]) + a[i];
        ans = max(ans, dp[i][0]);
        ans = max(ans, dp[i][1]);
        ans = max(ans, dp[i][2]);
    }
    printf("%lld\n", ans);
    return 0;
}
/*
5 -2
-3 8 -2 1 -6
*/