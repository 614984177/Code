#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, m, p[MAXN], cnt[MAXN];
vector<int> G[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &p[i]), cnt[p[i]] = n - i;
    while (m--)
    {
        int u, v; scanf("%d%d", &u, &v);
        G[v].push_back(u);
    }
    int ans = 0;
    for (int i = n; i >= 1; i--)
    {
        if (i != n && cnt[p[i]] == ans) ans++;
        else
        {
            for (int j : G[p[i]]) cnt[j]--;
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
2 1
1 2
1 2
*/