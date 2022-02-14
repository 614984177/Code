#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] < -nums[i]) l++;
                else if (nums[l] + nums[r] > -nums[i]) r--;
                else {                    
                    ans.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                    int x = nums[l], y = nums[r];
                    while (l < r && nums[l] == x) l++;
                    while (l < r && nums[r] == y) r--;
                }
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
    while (cin >> n)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int>> ans = AC.threeSum(a);
        for (auto &v : ans)
        {
            for (int i = 0; i < 3; i++) cout << v[i] << " ";
            cout << endl;
        }
    }
    return 0;
}
/*
6
-1 0 1 2 -1 -4
*/