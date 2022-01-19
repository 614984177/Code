#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
char s[MAXN];
int dis(char a, char b)
{
    return min((a - b + 26) % 26, (b - a + 26) % 26);
}
int main()
{
    scanf("%d%s", &n, s + 1);
    int ans = INF;
    for (int i = 4; i <= n; i++)
        ans = min(ans, dis(s[i - 3], 'A') + dis(s[i - 2], 'C') + dis(s[i - 1], 'T') + dis(s[i], 'G'));
    printf("%d\n", ans);
    return 0;
}
/*
4
ZCTH
*/