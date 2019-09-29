#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty()) return vector<vector<int>>();
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        vector<vector<int>> ans;
        int L = intervals[0][0], R = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++)
        {
            int l = intervals[i][0], r = intervals[i][1];
            if (L <= l && l <= R) R = max(R, r);
            else ans.emplace_back(vector<int>{L, R}), L = l, R = r;
        }
        ans.emplace_back(vector<int>{L, R});
        return ans;
    }
};
int main()
{
    Solution AC;
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    vector<vector<int>> ans = AC.merge(a);
    for (auto i : ans)
    {
        cout << i[0] << " " << i[1] << endl;
    }
    return 0;
}
/*
4
1 3
2 6
8 10
15 18
*/