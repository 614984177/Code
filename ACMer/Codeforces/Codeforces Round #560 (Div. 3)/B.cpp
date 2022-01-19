#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = 0, cnt = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < cnt) continue;
        ans++, cnt++;
    }
    printf("%d\n", ans);
    return 0;
}
/*
4
3 1 4 1
*/