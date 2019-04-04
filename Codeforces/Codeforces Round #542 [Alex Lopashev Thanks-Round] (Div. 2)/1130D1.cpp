#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
const int INF = 0x3f3f3f3f;
int n, m, num[MAXN], cnt[MAXN];
int dis(int u, int v){ return (v - u + n) % n; }
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        if (!num[u]) num[u] = v;
        else
        {
            cnt[u]++;
            if (dis(u, v) < dis(u, num[u])) num[u] = v;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = 0;
        for (int j = 1; j <= n; j++)
        {
            if (num[j])
                ans = max(ans, dis(i, j) + cnt[j] * n + dis(j, num[j]));
        }
        printf("%d ", ans);
    }
    return 0;
}
/*
5 7
2 4
5 1
2 3
3 4
4 1
5 3
3 5
*/