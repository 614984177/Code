#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long LL;
const int MOD = 1e9 + 7;
LL value[MAXN];
int prime[MAXN], tot;
bool vis[MAXN];
LL qpow(LL a, int b, int MOD)
{
    LL res = 1;
    while (b)
    {
        if (b&1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void GetPrime(int n)
{
    vis[0] = vis[1] = 1;
    value[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        { 
            prime[++tot] = i, vis[i] = true;
            value[i] = qpow(i, n, MOD);
        }
        for (int j = 1; j <= tot && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = true;
            value[i * prime[j]] = value[i] * value[prime[j]] % MOD;
            if (i % prime[j] == 0) break;
        }
    }
}

int main()
{
    int n; scanf("%d", &n);
    GetPrime(n);
    LL ans = 0;
    for (int i = 1; i <= n; i++) ans ^= value[i];
    printf("%lld\n", ans);
    return 0;
}
/*
3
*/