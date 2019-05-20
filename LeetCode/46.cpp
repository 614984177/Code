#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int>& vis, vector<int>& a, int cur)
    {
        if (cur == nums.size())
        {
            ans.emplace_back(a);
            return ;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i] == 1) continue;
            vis[i] = 1;
            a[cur] = nums[i];
            dfs(ans, nums, vis, a, cur + 1);
            vis[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> a(nums.size(), 0);
        vector<int> vis(nums.size(), 0);
        dfs(ans, nums, vis, a, 0);
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
        vector<vector<int>> ans = AC.permute(a);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
/*
3
1 2 3
*/