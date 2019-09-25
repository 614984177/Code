#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    void dfs(int l, int r, string cur, vector<string> &ans)
    {
        if (l == 0 && r == 0)
        {
            ans.emplace_back(cur);
            return ;
        }
        if (l > 0) 
            dfs(l - 1, r, cur + "(", ans);
        if (l < r)
            dfs(l, r - 1, cur + ")", ans);
    }
    vector<string> generateParenthesis(int n) 
    {
        if (n == 0) return vector<string>();
        vector<string> ans;
        dfs(n, n, "", ans);
        return ans;
    }
};
int main()
{
    Solution AC;
    int n; cin >> n;
    vector<string> ans = AC.generateParenthesis(n);
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}
/*
3
*/