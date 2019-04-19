#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int n, m, a[MAXN][MAXN], ans[MAXN];
bool solve(int sum)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= m; j++)
        {
            if (a[i][j] == a[i][1]) continue;
            ans[i] = j;
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
        sum ^= a[i][1];
        ans[i] = 1;
    }
    if (!sum && !solve(sum)) { printf("NIE\n"); return 0; }
    printf("TAK\n");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}
/*
3 2
0 0
0 0
0 0
*/