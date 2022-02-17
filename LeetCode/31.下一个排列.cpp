#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
class Solution 
{
public:
    void nextPermutation(vector<int>& nums) 
    {
        if (nums.size() <= 1) return ;
        int i = nums.size() - 1;
        while (i - 1 >= 0 && nums[i - 1] >= nums[i]) i--;
        reverse(nums.begin() + i, nums.end());
        if (i-- != 0)
        {
            auto j = upper_bound(nums.begin() + i, nums.end(), nums[i]);
            swap(nums[i], *j);
        }
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> a(n, -1);
    for (int i = 0; i < n; i++) cin >> a[i];
    AC.nextPermutation(a);
    for (auto i : a) cout << i << " ";
    cout << endl;
    return 0;
}
/*
3
1 2 3
3
3 2 1
*/