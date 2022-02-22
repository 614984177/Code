#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, g = 0;
        string ans;
        while (i >= 0 || j >= 0 || g) {
            if (i >= 0) g += int(num1[i] - '0'), i--;
            if (j >= 0) g += int(num2[j] - '0'), j--;
            ans += char('0' + g % 10);
            g = g / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// @lc code=end
int main()
{
    Solution AC;
    string a, b;
    while (cin >> a >> b)
    {
        cout << AC.addStrings(a, b) << endl;
    }
    return 0;
}
/*
11 123
*/