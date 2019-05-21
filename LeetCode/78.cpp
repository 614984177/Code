#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans(1 << nums.size(), vector<int>());
        for (int i = 0; i < (1 << nums.size()); i++)
        {
            for (int j = 0; j < nums.size(); j++)
            {
                if (i & (1 << j)) ans[i].emplace_back(nums[j]);
            }
        }
        return ans;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<vector<int>> ans = AC.subsets(a);
        for (int i = 0; i < ans.size(); i++)
        {
            for (auto j : ans[i]) cout << j << " ";
            cout << endl;
        }
    }
    return 0;
}
/*
3
1 2 3
*/