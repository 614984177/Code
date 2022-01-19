#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, a[MAXN], b[MAXN];
map<pair<int, int>, int> mp;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int zero = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        if (a[i] == 0 && b[i] == 0) zero++;
        if (a[i] == 0) continue;
        int G = __gcd(a[i], b[i]);
        a[i] /= G, b[i] /= G;
        if (a[i] > 0 && b[i] < 0) a[i] = -a[i], b[i] = -b[i];
        mp[make_pair(a[i], b[i])]++;
    }
    int ans = 0;
    for (auto i : mp) ans = max(ans, i.second);
    printf("%d\n", ans + zero);
    return 0;
}
/*
5
1 2 3 4 5
2 4 7 11 3
*/