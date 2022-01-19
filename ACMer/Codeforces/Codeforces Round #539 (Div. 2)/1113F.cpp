#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long LL;
const int MOD = 1e9 + 7;
int n, m, a, b;
LL f[MAXN], inv[MAXN];
LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b&1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}
void init(int n)
{
    f[0] = inv[0] = 1;
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % MOD;
    inv[n] = qpow(f[n], MOD - 2);
    for (int i = n - 1; i > 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
}
LL A(LL n, LL m)
{
    if (n < m || n < 0 || m < 0) return 0;
    return f[n] * inv[n - m] % MOD;
}
LL C(LL n, LL m)
{
    if (n < m || n < 0 || m < 0) return 0;
    return f[n] * inv[n - m] % MOD * inv[m] % MOD;
}
LL cayley(LL x)
{
    if (x == n - 1) return 1;
    return (x + 1) % MOD * qpow(n, n - x - 2) % MOD;
}
LL cal(int x)
{
    return A(n - 2, x - 1) % MOD * C(m - 1, x - 1)  % MOD * qpow(m, n - x - 1) % MOD * cayley(x) % MOD;
}
int main()
{
    init(MAXN - 1);
    scanf("%d%d%d%d", &n, &m, &a, &b);
    LL ans = 0;
    for (int i = 1; i <= n - 1; i++)
        ans = (ans + cal(i)) % MOD;
    printf("%lld\n", ans);
    return 0;
}
/*
3 2 1 3
*/