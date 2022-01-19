#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k, a[MAXN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int x; scanf("%d", &x);
        a[x % k]++;
    }
    int cnt = 0;
    for (int i = 1; i < (k + 1) / 2; i++) cnt += min(a[i], a[k - i]);
    printf("%d\n", cnt * 2 + a[0] / 2 * 2 + (k % 2 == 0 ? a[k / 2] / 2 * 2 : 0));
    return 0;
}
/*
7 2
1 2 2 3 2 4 10
*/