#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
int n, m, a[MAXN], b[MAXN], cnt[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    LL sum = 0, ans = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]), ans += b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    if (b[1] < a[n]) { printf("-1\n"); return 0; }
    ans += (sum - a[n]) * m;
    if (b[1] != a[n]) ans += a[n] - a[n - 1];
    printf("%lld\n", ans);
    return 0;
}
/*
3 2
1 2 1
3 4
*/