#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long LL;
int n;
int main()
{
    scanf("%d", &n);
    LL ans = 0;
    for (int i = 2; i < n; i++) ans += i * (i + 1);
    printf("%lld\n", ans);
    return 0;
}
/*
3
*/