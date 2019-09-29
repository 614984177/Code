#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> mp;
        for (auto i : strs)
        {
            auto t = i;
            sort(t.begin(), t.end());
            mp[t].emplace_back(i);
        }
        vector<vector<string>> ans;
        for (auto i : mp)
        {
            ans.emplace_back(i.second);
        }
        return ans;
    }
};

int main()
{
    Solution AC;
    int n; cin >> n;
    vector<string> str(n, "");
    for (int i = 0; i < n; i++) cin >> str[i];
    vector<vector<string>> ans = AC.groupAnagrams(str);
    for (auto i : ans)
    {
        for (auto j : i) cout << j << " ";
        cout << endl;
    }
    return 0;
}
/*
6
eat tea tan ate nat bat
*/