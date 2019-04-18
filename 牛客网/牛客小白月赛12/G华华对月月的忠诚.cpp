#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
LL a, b;
int main()
{
    scanf("%lld%lld%*d", &a, &b);
    printf("%lld\n", __gcd(a, b));
    return 0;
}
/*
2 4 5
*/