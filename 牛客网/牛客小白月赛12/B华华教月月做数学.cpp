#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
LL mul(LL a, LL b, LL MOD)
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
/*LL mul(LL a, LL b, LL MOD) // O(1)快速乘,会有精度误差
{
    LL res = a * b - (LL)((long double)a * b / MOD + 0.5) * MOD;
    return (res + MOD) % MOD;  //就是算的a*b%m;
}*/
LL qpow(LL a, LL b, LL MOD)
{
    LL res = 1;
    while (b)
    {
        if (b&1) res = mul(res, a, MOD);
        a = mul(a, a, MOD);
        b >>= 1;
    }
    return res;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        LL A, B, P; scanf("%lld%lld%lld", &A, &B, &P);
        printf("%lld\n", qpow(A, B, P));
    }
    return 0;
}
/*
2
2 5 10
57284938291657 827493857294857 384729583748273
*/