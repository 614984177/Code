#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
map<int, LL> mp;
LL qpow(LL a, LL b, LL MOD)
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
int phi(int x)
{
    int res = x;
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0) res -= res / i;
        while (x % i == 0) x /= i;
    }
    if (x > 1) res -= res / x;
    return res;
}
LL solve(int p)
{
    if (mp.count(p))
        return mp[p];
    int x = phi(p);
    return mp[p] = qpow(2, solve(x) + x, p); 
}
int main()
{
    mp[1] = 0;
    int T; scanf("%d", &T);
    while (T--)
    {
        int p; scanf("%d", &p);
        printf("%lld\n", solve(p));
    }    
    return 0;
}
/*
3
2
3
6
*/