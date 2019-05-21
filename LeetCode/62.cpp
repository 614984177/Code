#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m + 5, vector<int>(n + 5, 0));
        dp[1][1] = 1;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] += dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
        // C(m + n - 2, m - 1)。
    }
};
int main()
{
    Solution AC;
    int n, m;
    while (cin >> m >> n)
    {
        cout << AC.uniquePaths(m, n) << endl;
    }
    return 0;
}
/*
3 2
*/