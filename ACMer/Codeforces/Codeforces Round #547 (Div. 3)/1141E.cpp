#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long LL;
int n;
LL H, d[MAXN];
int main()
{
    scanf("%lld%d", &H, &n);
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &d[i]), d[i] += d[i-1];
        if (d[i] < d[pos]) pos = i;
    }
    if (H + d[pos] > 0 && d[n] >= 0) { printf("-1"); return 0; }
    //cout << d[pos] << " " << d[n] << endl;
    LL ans = 0;
    if (d[n] && H + d[pos] > 0) ans = (H + d[pos]) / abs(d[n]) + ((H + d[pos]) % abs(d[n]) != 0);
    H -= ans * abs(d[n]);
    ans *= n;
    for (int i = 0; i <= n; i++)
        if (H + d[i] <= 0){ printf("%lld\n", ans + i); break; }
    return 0;
}
/*
1000000000000 5
-1 0 0 0 0
*/