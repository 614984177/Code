#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    vector<int> grayCode(int n) 
    {
        vector<int> ans;
        for (int i = 0; i < (1 << n); i++)
            ans.emplace_back(i ^ (i >> 1));
        return ans;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> ans = AC.grayCode(n);
        for (auto i : ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
/*
2
*/