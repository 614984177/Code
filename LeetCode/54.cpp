#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        if (matrix.empty()) return vector<int>();
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;
        int x = 0, y = 0, tot = 0;
        tot++, ans.emplace_back(matrix[x][y]), vis[x][y] = -1;
        while (tot < n * m)
        {
            while (y + 1 < m && !vis[x][y + 1]) tot++, ans.emplace_back(matrix[x][y + 1]), vis[x][++y] = 1;
            while (x + 1 < n && !vis[x + 1][y]) tot++, ans.emplace_back(matrix[x + 1][y]), vis[++x][y] = 1;
            while (y - 1 >= 0 && !vis[x][y - 1]) tot++, ans.emplace_back(matrix[x][y - 1]), vis[x][--y] = 1;
            while (x - 1 >= 0 && !vis[x - 1][y]) tot++, ans.emplace_back(matrix[x - 1][y]), vis[--x][y] = 1;
        }
        return ans;
    }
};
int main()
{
    Solution AC;
    int n, m;
    while (cin >> n >> m)
    {
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }
        vector<int> ans = AC.spiralOrder(v);
        for (auto i: ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
/*
3 3
1 2 3
4 5 6
7 8 9
*/