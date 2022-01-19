#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long LL;
int n, m;
LL a[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    LL g = 0;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%lld", &a[i]);
        if (i > 1) g = __gcd(g, a[i] - a[i - 1]);
    }
    int ans = -1;
    for (int i = 1; i <= m; i++)
    {
        LL x; scanf("%lld", &x);
        if (g % x == 0) ans = i;
    }
    if (ans != -1) printf("YES\n%lld %d\n", a[1], ans);
    else printf("NO\n");
    return 0;
}
/*
3 5
3 12 18
2 6 5 3 3
*/