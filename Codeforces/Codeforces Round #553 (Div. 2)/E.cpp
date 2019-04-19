#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, a[MAXN];
long long ans;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == a[i - 1]) continue;
        if (a[i] > a[i - 1]) ans += 1LL * (a[i] - a[i - 1]) * (n - a[i] + 1);
        if (a[i] < a[i - 1]) ans += 1LL * (a[i - 1] - a[i]) * a[i];
    }
    printf("%lld\n", ans);
    return 0;
}
/*
3
2 1 3
*/