#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, m, r, a[MAXN], b[MAXN];
int main()
{
	scanf("%d%d%d", &n, &m, &r);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%d", &b[i]);
    int MIN = *min_element(a + 1, a + n + 1), MAX = *max_element(b + 1, b + m + 1);
    int ans = r % MIN + r / MIN * MAX;
    if (MIN >= MAX) ans = r;
    printf("%d\n", ans);
	return 0;
}
/*
3 4 11
4 2 5
4 4 5 4
*/