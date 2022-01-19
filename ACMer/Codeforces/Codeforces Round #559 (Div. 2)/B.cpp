#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
const int INF = 0x3f3f3f3f;
int n, a[MAXN], pre[MAXN], suf[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], a[i]);
    for (int i = n; i >= 1; i--) suf[i] = max(suf[i + 1], a[i]);
    reverse(suf + 1, suf + n + 1);
    int ans = INF;
    for (int i = 1; i <= n; i++)
    {
        int L = lower_bound(pre + 1, pre + n + 1, a[i]) - pre;
        int R = lower_bound(suf + 1, suf + n + 1, a[i]) - suf;
        int MAX = 0;
        if (L != i) MAX = max(MAX, i - L);
        if (n - R + 1 != i) MAX = max(MAX, n - R + 1 - i);
        if (MAX == 0) continue;
        ans = min(ans, a[i] / MAX);
    }
    printf("%d\n", ans);
    return 0;
}
/*
4
6 4 5 5
*/