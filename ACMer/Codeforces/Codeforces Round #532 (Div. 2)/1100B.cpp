#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, m, a[MAXN], cnt[MAXN];
set<int> s;
int main()
{
    scanf("%d%d", &m, &n);
    string ans;
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        s.insert(a[i]);
        cnt[a[i]]++;
        if (s.size() == m)
        {
            for (int j = 1; j <= m; j++)
            {
                cnt[j]--;
                if (cnt[j] == 0) s.erase(j);
            }
            ans += '1';
        }
        else ans += '0';
    }
    cout << ans << endl;
    return 0;
}
/*
3 11
2 3 1 2 2 2 3 2 2 3 1
*/