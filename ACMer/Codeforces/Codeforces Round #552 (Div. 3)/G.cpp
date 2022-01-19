#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;
typedef long long LL;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, idx[MAXN];
int main()
{
    scanf("%d", &n);
    int A, B, MAX = 0;
    LL lcm = INF;
    for (int i = 1; i <= n; i++)
    {
        int x; scanf("%d", &x);
        MAX = max(MAX, x);
        if (idx[x] && x < lcm)
        {
            lcm = x;
            A = idx[x], B = i;
        }
        idx[x] = i;
    }
    for (int i = 1; i <= MAX; i++)
    {
        vector<int> v;
        for (int j = i; j <= MAX; j += i)
        {
            if (idx[j]) v.emplace_back(j);
            if (v.size() >= 2) break;
        }
        if (v.size() < 2) continue;
        LL x = 1LL * v[0] * v[1] / __gcd(v[0], v[1]);
        if (x < lcm)
        {
            lcm = x;
            A = idx[v[0]], B = idx[v[1]];
        }
    }
    printf("%d %d", min(A, B), max(A, B));
    return 0;
}
/*
5
2 4 8 3 6
*/