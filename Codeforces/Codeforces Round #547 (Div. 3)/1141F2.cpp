#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e3 + 5;
#define X first
#define Y second
int n, a[MAXN];
map<int, vector<pair<int, int>>> mp;
int main()
{
    //freopen("in", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), a[i] += a[i - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            mp[a[j]-a[i-1]].push_back(make_pair(i, j));
        }
    }
    int ans = 0, MAX = -1;
    for (auto i : mp)
    {
        vector<pair<int, int>>& v = i.Y;
        sort(v.begin(), v.end(),
             [](pair<int, int> a, pair<int, int> b){ return a.Y < b.Y; });
        int cnt = 0, r = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j].X <= r) continue;
            cnt++, r = v[j].Y;
        }
        if (cnt > MAX) MAX = cnt, ans = i.X;
    }
    vector<pair<int, int>>& v = mp[ans];
    sort(v.begin(), v.end(),
             [](pair<int, int> a, pair<int, int> b){ return a.Y < b.Y; });
    printf("%d\n", MAX);
    int r = 0;
    for (int j = 0; j < v.size(); j++)
    {
        if (v[j].X <= r) continue;
        printf("%d %d\n", v[j].X, v[j].Y);
        r = v[j].Y;
    }
    return 0;
}
/*
7
4 1 2 2 1 5 3
*/