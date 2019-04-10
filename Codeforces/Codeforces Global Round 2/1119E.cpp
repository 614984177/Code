#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long LL;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    LL ans = a[0] / 3;
    a[0] %= 3;
    for (int i = 1; i < n; i++)
    {
        int t = min(a[i-1], a[i]/2);
        ans += t;
        a[i - 1] -= t;
        a[i] -= 2 * t;
        ans += a[i] / 3;
        a[i] %= 3;
        a[i] += a[i-1];
    }
    printf("%lld\n", ans);
    return 0;
}
/*
5
1 2 2 2 2
*/