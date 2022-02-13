#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char, int> mp;
        int ans = 0, l = 0, r = 0;
        while (r < s.size())
        {
            if (mp.count(s[r])) l = max(l, mp[s[r]] + 1);
            ans = max(ans, r - l + 1);
            mp[s[r]] = r;
            r++;
        }
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution AC;
    string s; cin >> s;
    cout << AC.lengthOfLongestSubstring(s) << endl;
    return 0;
}
/*
abcabcbb
 
*/