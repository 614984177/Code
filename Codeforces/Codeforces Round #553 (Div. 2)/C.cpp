#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
const int MOD = 1e9 + 7;
LL L, R, a[MAXN];
LL mul(LL a, LL b)
{
    LL res = 0;
    while (b)
    {
        if (b&1) res = (res + a) % MOD;
        a = (a + a) % MOD;
        b >>= 1;
    }
    return res;
}
LL sum (LL x)
{
    LL odd = 0, even = 0, t = 0;
    while (x > 0)
    {

        if (t%2) even += min(x, 1LL<<t);
        else odd += min(x, 1LL<<t);
        x -= 1LL<<t;
        t++;
    }
    return (mul(odd, odd) + mul(even, even + 1)) % MOD;
}
int main()
{

    scanf("%lld%lld", &L, &R);
    printf("%lld\n", (sum(R) - sum(L - 1) + MOD) % MOD);
    return 0;
}
/*
1 3
*/