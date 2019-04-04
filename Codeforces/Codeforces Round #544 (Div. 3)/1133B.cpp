#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, k, a[MAXN];
set<int> s[105];
bool vis[MAXN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), s[a[i] % k].insert(i);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int t1 = a[i] % k, t2 = (k - a[i] % k) % k;
        if (!s[t1].count(i)) continue;
        s[t1].erase(i);
        if (!s[t2].empty())
        {
            int pos = *s[t2].begin();
            s[a[pos] % k].erase(pos);
            ans++;
            //cout << i << " " << pos << endl;
        }
    }
    printf("%lld\n", ans * 2);
    return 0;
}
/*
7 2
1 2 2 3 2 4 10
*/