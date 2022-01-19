#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
int n, a[MAXN];
LL len;
bool check(int x)
{
    LL cnt = 0;
    int j = 2;
    for (int i = 1; i <= n; i++)
    {
        while (j <= n && a[j] - a[i] <= x) j++;
        cnt += j - i - 1;
    }
    return cnt >= len / 2;
}
int main()
{
    while (~scanf("%d", &n))
    {
        len = 1LL * n * (n - 1) / 2;
        if (len&1) len++;
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        sort(a + 1, a + n + 1);
        int L = 0, R = a[n] - a[1] + 1;
        while (L < R)
        {
            int m = L + (R - L) / 2;
            if (check(m)) R = m;
            else L = m + 1;
        }
        printf("%d\n", L);
    }
    return 0;
}
/*
4
1 3 2 4
3
1 10 2
*/