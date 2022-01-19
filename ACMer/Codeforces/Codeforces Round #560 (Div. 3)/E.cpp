#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MAXN = 2e5 + 5;
typedef long long LL;
const int MOD = 998244353;
int n;
pair<int, LL> a[MAXN], b[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        a[i].X = i;
        scanf("%lld", &a[i].Y);
        a[i].Y *= 1LL * i * (n - i + 1);
    }
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i].Y);
    sort(a + 1, a + n + 1, [](const pair<int, LL> &a, const pair<int, LL> &b){
        return a.Y < b.Y;
    });
    sort(b + 1, b + n + 1, [](const pair<int, LL> &a, const pair<int, LL> &b){
        return a.Y > b.Y;
    });
    for (int i = 1; i <= n; i++) b[i].X = a[i].X;
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    LL ans = 0; 
    for (int i = 1; i <= n; i++) ans = (ans + a[i].Y % MOD * b[i].Y % MOD) % MOD;
    printf("%lld\n", ans);
    return 0;
}
/*
5
1 8 7 2 4
9 7 2 9 3
*/