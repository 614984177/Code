#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
int n;
LL a[MAXN];
int main()
{
    int kase = 1;
	while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        LL ans = 0;
        for (int l = 1; l <= n; l++)
        {
            for (int r = l; r <= n; r++)
            {
                LL t = 1;
                for (int i = l; i <= r; i++) t *= a[i];
                ans = max(ans, t);
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", kase++, ans);
    }
	return 0;
}
/*
3
2 4 -3
5
2 5 -1 2 -1
*/