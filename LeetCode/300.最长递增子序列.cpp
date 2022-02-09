#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int len = 1;
        for(int i = 1; i < nums.size(); i++)
        {
            int pos = lower_bound(dp.begin(), dp.begin() + len, nums[i]) - dp.begin();
            if(pos < len) dp[pos] = nums[i];
            else dp[len++] = nums[i];
        }
        return len;
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
        cout << AC.lengthOfLIS(a) << endl;
    }
    return 0;
}
/*
8
10 9 2 5 3 7 101 18
*/