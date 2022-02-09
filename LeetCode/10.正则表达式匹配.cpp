#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size()+5, vector<bool>(p.size()+5, 0));
        dp[0][0] = 1;
        for (int i = 2; i <= p.size(); i++)
            dp[0][i] = dp[0][i - 2] && (p[i - 1] == '*');
        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 1; j <= p.size(); j++)
            {
                if (j > 1 && p[j - 1] == '*')
                {
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};
// @lc code=end

int main()
{
    Solution AC;
    string s, p;
    cin >> s >> p;
    cout << (AC.isMatch(s, p) ? "YES" : "NO") << endl;
    return 0;
}
/*
aab
c*a*b
*/