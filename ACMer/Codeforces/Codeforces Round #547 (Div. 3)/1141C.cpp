#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long LL;
int n;
LL q[MAXN], p[MAXN];
bool vis[MAXN];
int main()
{
    scanf("%d", &n);
    LL sum = 0;
    for (int i = 1; i < n; i++)
    {
        scanf("%lld", &q[i]);
        q[i] += q[i-1];
        sum += q[i];
    }
    //n * (n + 1) / 2  = n * x + sum
    LL t = 1LL * n * (n + 1) / 2 - sum;
    LL x = t / n;
    if (t % n) { printf("-1\n"); return 0; }
    for (int i = 0; i < n; i++)
    {
        p[i] = q[i] + x;
        if (p[i] < 1 || p[i] > n || vis[p[i]])  { printf("-1\n"); return 0; }
        vis[p[i]] = true;
    }
    for (int i = 0; i < n; i++) printf("%lld ", p[i]);
    return 0;
}
/*
3
-2 1
*/