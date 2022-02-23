#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1, ans = 0;
        while (i < s.size() && s[i] == ' ') {
            i++;
        }
        if (s[i] == '+') {
            sign = 1, i++;
        }
        else if (s[i] == '-') {
            sign = -1, i++;
        }
        while (i < s.size() && isdigit(s[i])) {
            int t = s[i] - '0';
            if (ans > INT_MAX/10 || ans == INT_MAX/10 && t > 7) {
                return INT_MAX;
            }
            if (ans < INT_MIN/10 || ans == INT_MIN/10 && t > 8) {
                return INT_MIN;
            }
            ans = ans * 10 + sign * t;
            i++;
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution AC;
    string s;
    while (getline(cin, s))
    {
        printf("%d\n", AC.myAtoi(s));
    }
    return 0;
}
/*
42
   -42
4193 with words
words and 987
-91283472332
*/