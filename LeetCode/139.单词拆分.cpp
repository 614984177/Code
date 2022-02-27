
#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, 0);
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int max_ = 0;
        dp[0] = true;
        for (auto word: wordDict) max_ = max(max_, int(word.size()));
        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (i - j > max_) break;
                if (st.count(s.substr(j, i - j)) && dp[j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n;
    string s;
    while (cin >> n >> s)
    {
        vector<string> a;
        for (int i = 1; i <= n; i++){
            string x; cin >> x;
            a.emplace_back(x);
        }
        cout << AC.wordBreak(s, a) << endl;
    }
    return 0;
}
/*
2
leetcode
leet
code
2
applepenapple
apple
pen
5
catsandog
cats
dog
sand
and
cat
1
a
a
*/