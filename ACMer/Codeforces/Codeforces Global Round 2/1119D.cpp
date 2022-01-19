#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
int n;
LL a[MAXN], b[MAXN], sum[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    for (int i = 2; i <= n; i++) b[i] = a[i] - a[i - 1];
    sort(b + 2, b + n + 1);
    for (int i = 2; i <= n; i++) sum[i] = sum[i - 1] + b[i];
    int q; scanf("%d", &q);
    while (q--)
    {
        LL l, r; scanf("%lld%lld", &l, &r);
        LL w = r - l + 1;
        int idx = lower_bound(b + 2, b + n + 1, w) - b;
        LL ans = sum[idx - 1] +  (n + 1 - idx) * w + w;
        printf("%lld \n", ans);
    }
    return 0;
}
/*
6
3 1 4 1 5 9
3
7 7
0 2
8 17
*/