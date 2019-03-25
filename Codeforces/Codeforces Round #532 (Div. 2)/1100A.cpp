#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, k, a[MAXN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = 0;
    for (int b = 1; b <= k; b++)
    {
        int x1 = 0, x2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if ((i - b) % k == 0) continue;
            if (a[i] == 1) x1++;
            else x2++;
        }
        ans = max(ans, abs(x1 - x2));
    }
    printf("%d\n", ans);
    return 0;
}
/*
4 2
1 1 -1 1
*/