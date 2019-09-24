#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    unordered_map<char, string> mp{
        {'1', "!@#"}, {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
        {'7', "pqrs"}, {'8', "tuv"},{'9', "wxyz"}
    };
    void dfs(string digits, string cur, vector<string> &ans)
    {
        if (digits == "")
        {
            ans.emplace_back(cur);
            return ;
        }
        for (auto i : mp.at(digits[0]))
            dfs(digits.substr(1, digits.size() - 1), cur + i, ans);
    }
    vector<string> letterCombinations(string digits) 
    {
        if (digits.empty()) return vector<string>();
        vector<string> ans;
        dfs(digits, "", ans);
        return ans;
    }
};
int main()
{
    Solution AC;
    string s; cin >> s;
    vector<string> ans = AC.letterCombinations(s);
    for (const auto &i : ans)
        cout << i << endl;
    return 0;
}
/*
23
*/