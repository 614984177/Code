#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
class Solution 
{
public:
    int longestConsecutive(vector<int>& nums) 
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        while (!s.empty())
        {
            int now = *s.begin();
            int l = now - 1, r = now + 1;
            s.erase(now);
            while (s.find(l) != s.end()) s.erase(l), l--;
            while (s.find(r) != s.end()) s.erase(r), r++;
            ans = max(ans, r - l - 1);
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
        cout << AC.longestConsecutive(a) << endl;
    }
    return 0;
}
/*
6
100 4 200 1 3 2
10
0 3 7 2 5 8 4 6 0 1
6
6 4 5 1 2 3
*/