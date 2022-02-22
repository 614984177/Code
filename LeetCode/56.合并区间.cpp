#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if (intervals.empty()) return ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        for (int i = 0; i < intervals.size(); i++) {
            int l = intervals[i][0], r = intervals[i][1];
            if (ans.empty() || ans.back()[1] < l) {
                ans.emplace_back(vector<int>{l, r});
            } else {
                ans.back()[1] = max(ans.back()[1], r);
            }
        }
        return ans;
    }
};
// @lc code=end
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