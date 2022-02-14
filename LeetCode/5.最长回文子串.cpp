#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    pair<int, int> centerExtend(string s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) l--, r++;
        return {l + 1, r};
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            int l1, r1, l2, r2;
            tie(l1, r1) = centerExtend(s, i, i);
            tie(l2, r2) = centerExtend(s, i, i + 1);
            if (r1 - l1 > end - start) start = l1, end = r1;
            if (r2 - l2 > end - start) start = l2, end = r2;
        }
        return s.substr(start, end - start);
    }
};
// @lc code=end
int main()
{
    Solution AC;
    string s;
    while (cin >> s)
    {
        cout << AC.longestPalindrome(s) << endl;
    }
    return 0;
}
/*
babad
cbbd
*/