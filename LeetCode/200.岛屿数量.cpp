#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
    int n, m, cnt;
    const int dx[4] = {0, 0, 1, -1};
    const int dy[4] = {-1, 1, 0, 0};
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }

    void dfs(vector<vector<char>>& grid, int x, int y) {
        grid[x][y] = '0';
        for (int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= 0 && yy >= 0 && xx < n && yy < m && grid[xx][yy] == '1')
                dfs(grid, xx, yy);
        }
    }
};
// @lc code=end
int main() {
    Solution AC;
    int n, m;
    while (cin >> n >> m) {
        vector<vector<char>> a(n, vector<char>(m, 0));
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                cin >> a[i][j];
        cout << AC.numIslands(a) << endl;
    }
    return 0;
}
/*
4 5
1 1 1 1 0
1 1 0 1 0
1 1 0 0 0
0 0 0 0 0
*/

