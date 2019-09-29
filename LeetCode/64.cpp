#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        const int INF = 0x3f3f3f3f;
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n + 5, vector<int>(m + 5, INF));
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
                if (j - 1 >= 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
            }
        }
        return dp[n - 1][m - 1];
    }
};
int main()
{
    Solution AC;
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    cout << AC.minPathSum(a) << endl;
    return 0;
}
/*
3 3
1 3 1
1 5 1
4 2 1
*/