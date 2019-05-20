#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int x = 0, y = 0, tot = 0;
        ans[x][y] = ++tot;
        while (tot < n * n)
        {
            while (y + 1 < n && !ans[x][y + 1]) ans[x][++y] = ++tot;
            while (x + 1 < n && !ans[x + 1][y]) ans[++x][y] = ++tot;
            while (y - 1 >= 0 && !ans[x][y - 1]) ans[x][--y] = ++tot;
            while (x - 1 >= 0 && !ans[x - 1][y]) ans[--x][y] = ++tot;
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
        vector<vector<int>> ans = AC.generateMatrix(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
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
*/