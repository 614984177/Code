#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    if (n == 1) printf("0\n");
    else if (n == 2) printf("%d\n", (a[2] - a[1]) % 2 ? a[2] - a[1] : (a[2] - a[1]) / 2 );
    else if (n == 3 && a[2] - a[1] == a[3] - a[2]) printf("%d\n", a[2] - a[1]);
    else printf("-1\n");
	return 0;
}
/*
6
1 4 4 7 4 1
*/