#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t = upper_bound(a, a + n, a[i] + 5) - lower_bound(a, a + n, a[i]);
        ans = max(ans, t);
    }
    printf("%d\n", ans);
    return 0;
}
/*
6
1 10 17 12 15 2
*/