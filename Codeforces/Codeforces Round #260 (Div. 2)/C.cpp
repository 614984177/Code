#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
int n, a[MAXN];
LL dp[MAXN];
int main()
{
    scanf("%d", &n);
    int MAX = 0;
    for (int i = 1; i <= n; i++)
    {
        int x; scanf("%d", &x);
        a[x]++;
        MAX = max(MAX, x);
    }
    for (int i = 1; i <= MAX; i++)
        dp[i] = max(dp[i - 1], dp[i - 2] + 1LL * i * a[i]);
    printf("%lld\n", dp[MAX]);
    return 0;
}
/*
9
1 2 1 3 2 2 2 2 3
*/