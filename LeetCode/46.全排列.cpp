#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> a;
    vector<bool> vis;
    vector<vector<int>> permute(vector<int>& nums) {
        a = vector<int>(nums.size(), 0);
        vis = vector<bool>(nums.size(), false);
        dfs(0, nums);
        return ans;
    }

    void dfs(int x, vector<int>& nums) {
        if (x == nums.size()) {
            ans.emplace_back(a);
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (!vis[i]) {
                a[x] = nums[i];
                vis[i] = true;
                dfs(x+1, nums);
                vis[i] = false;
            }
        }
    }
};
// @lc code=end
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int>> ans = AC.permute(a);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/*
3
1 2 3
*/