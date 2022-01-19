#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n, a[MAXN], mul[MAXN], Div[MAXN];
int main()
{
    scanf("%d", &n);
    int sum = 0;
    memset(mul, INF, sizeof(mul));
    memset(Div, -1, sizeof(Div));
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]), sum += a[i];
        for (int x = 1; x <= 100; x++)
        {
            mul[x] = min(mul[x], a[i] * (x - 1));
            if (a[i] % x == 0) Div[x] = max(Div[x], a[i] - a[i] / x);
        }
    }
    int ans = INF;
    for (int x = 1; x <= 100; x++)
    {
        if (mul[x] == INF || Div[x] == -1) continue;
        ans = min(ans, sum + mul[x] - Div[x]);
    }
    printf("%d\n", ans);
    return 0;
}
/*
5
1 2 3 4 5
*/