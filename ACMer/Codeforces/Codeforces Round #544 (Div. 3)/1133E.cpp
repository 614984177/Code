#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const int INF = 0x3f3f3f3f;
int n, k, a[MAXN], dp[MAXN][MAXN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int l = 1;
    for (int i = 1; i <= n; i++)
    {
        while (l < i && a[i] - a[l] > 5) l++;
        for (int j = 1; j <= min(l, k); j++)
            dp[i][j] = max(dp[i - 1][j], dp[l - 1][j - 1] + i - l + 1);
    }
    printf("%d\n", *max_element(dp[n] + 1, dp[n] + 1 + k));
    return 0;
}
/*
5 2
1 2 15 15 15
*/