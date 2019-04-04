#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, l[MAXN], r[MAXN], t;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d%d", &l[i], &r[i]);
    scanf("%d", &t);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (l[i] <= t && t <= r[i]) { ans = n - i; break; }
    }
    printf("%d\n", ans);
    return 0;
}
/*
3
1 3
4 7
8 11
2
*/