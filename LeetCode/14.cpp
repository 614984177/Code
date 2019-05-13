#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if (strs.size() == 0) return "";
        string ans = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            for (int j = 0; j < ans.size(); j++)
            {
                if (ans[j] != strs[i][j])
                {
                    ans = ans.substr(0, j);
                    break;
                }
            }
            if (ans == "") break;
        }
        return ans;
    }
};
int n;
int main()
{
    Solution AC;
    while (cin >> n)
    {
        vector<string> v;
        for (int i = 1; i <= n; i++) 
        {
            string str; cin >> str;
            v.emplace_back(str);
        }
        cout << AC.longestCommonPrefix(v) << endl;
    }
    return 0;
}
/*
3
flower flow flight
3
dog racecar car
*/