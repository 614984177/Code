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
        int a[256 + 1];
        memset(a, 0, sizeof(a));
        int ans = 0, l = 0, r = 0;
        while (r < s.size())
        {
            l = max(l, a[(int)s[r]]);
            ans = max(ans, r - l + 1);
            a[(int)s[r]] = r + 1;
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