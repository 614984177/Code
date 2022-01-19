#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n;
pair<int, int> a[MAXN];
#define X first
#define Y second
int main()
{
    scanf("%d", &n); n *= 2;
    for (int i = 0; i < n; i++) scanf("%d", &a[i].X), a[i].Y = i;
    sort(a, a + n);
    long long ans = a[0].Y + a[1].Y;
    for (int i = 2; i < n; i += 2)
        ans += abs(a[i + 1].Y - a[i - 1].Y) + abs(a[i].Y - a[i - 2].Y);
    printf("%lld\n", ans);
    return 0;
}
/*
3
1 1 2 2 3 3
*/