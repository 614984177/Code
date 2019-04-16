#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
#define X first
#define Y second
int n, m;
pair<int, int> a[MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &a[i].X, &a[i].Y);
    sort(a + 1, a + m + 1);
    int R = 0, ans = 0;
    for (int i = 1; i <= m; )
    {
        if (a[i].X > R + 1 || R == n) break;
        int MAX = R;
        while (i <= m && a[i].X <= R + 1)
        {
            MAX = max(MAX, a[i].Y);
            i++;
        }
        R = MAX, ans++;
    }
    if (R == n) printf("%d\n", ans);
    else printf("-1\n");
    return 0;
}
/*
4 2
1 2
3 4
*/