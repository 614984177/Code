#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k, a[MAXN];
bool check(int x)
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        res += a[i] / x;
    return res >= k;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int L = 1, R = a[n] + 1;
    while (L < R)
    {
        int m = L + (R - L) / 2;
        if (check(m)) L = m + 1;
        else R = m;
    }
    printf("%d\n", L - 1);
    return 0;
}
/*
5 10
4 4 4 5 3
*/