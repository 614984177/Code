#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;
        int  l = 0, r = 0;
        while (r < nums.size())
        {
            if (!dq.empty() && dq.front() < l) dq.pop_front();
            while (!dq.empty() && nums[r] >= nums[dq.back()]) dq.pop_back();
            dq.push_back(r);
            if (r < k - 1) { r++; continue; }
            ans.emplace_back(nums[dq.front()]);
            l++, r++;
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution AC;
    int n, k;
    while (cin >> n >> k)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = AC.maxSlidingWindow(a, k);
        for (auto i : ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
/*
8 3
1 3 -1 -3 5 3 6 7
*/