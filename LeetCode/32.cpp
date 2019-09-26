#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
//直接统计l，r计算，从左到右扫描一遍，从右到左扫描一遍
class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        int l = 0, r = 0, ans = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') l++;
            else r++;
            if (l == r) ans = max(ans, r * 2);
            if (l < r) l = r = 0;
        }
        l = r = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (s[i] == '(') l++;
            else r++;
            if (l == r) ans = max(ans, l * 2);
            if (l > r) l = r = 0;
        }
        return ans;
    }
};
//栈记录l的位置
class Solution2
{
public:
    int longestValidParentheses(string s) 
    {
        int ans = 0;
        stack<int> sta;
        sta.push(-1);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(') sta.push(i);
            else 
            {
                sta.pop();
                if (sta.empty()) sta.push(i);
                else ans = max(ans, i - sta.top());
            }
        }
        return ans;
    }
};
//DP
class Solution3
{
public:
    int longestValidParentheses(string s) 
    {
        vector<int> dp(s.size() + 5, 0);
        int ans = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(') 
                {
                    if (i - 2 >= 0) dp[i] = dp[i - 2] + 2;
                    else dp[i] = 2;
                }
                else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(')
                {
                    if (i - dp[i - 1] - 2 >= 0) 
                        dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                    else
                        dp[i] = dp[i - 1] + 2;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
int main()
{
    Solution AC;
    string s; cin >> s;
    cout << AC.longestValidParentheses(s) << endl;
    return 0;
}
/*
)()())
()(()
)(
(()
)()())
*/