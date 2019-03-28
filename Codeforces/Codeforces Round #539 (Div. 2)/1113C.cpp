#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, a, cnt[2][1<<20];
int main()
{
    scanf("%d", &n);
    long long ans = 0;
    cnt[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int x; scanf("%d", &x);
        a ^= x;
        cnt[i%2][a]++;
        ans += cnt[i%2][a] - 1;
    }
    printf("%lld\n", ans);
    return 0;
}
/*
5
1 2 3 4 5
*/