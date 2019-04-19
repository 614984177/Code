#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
#define X first
#define Y second
typedef long long LL;
int n;
pair<int, int> a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].X, &a[i].Y);
    sort(a + 1, a + n + 1, [](const pair<int, int> &a, const pair<int, int> &b)
         {
             return a.Y - a.X < b.Y - b.X;
         });
    LL ans = 0;
    for (int i = 1; i <= n; i++) ans += 1LL * a[i].X * (i - 1) + 1LL * a[i].Y * (n - i);
    printf("%lld\n", ans);
    return 0;
}
/*
3
4 2
2 3
6 1
*/