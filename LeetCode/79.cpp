#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        if (board.empty() || word.empty()) return false;
        int n = board.size(), m = board[0].size();
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        function<bool(int x, int y, int idx)> dfs = [&](int x, int y, int idx)->bool
        {
            if (idx == word.size() - 1) return board[x][y] == word[idx];
            if (board[x][y] != word[idx]) return false;
            vis[x][y] = 1;
            for (int i = 0; i < 4; i++)
            {
                int xx = x + dx[i], yy = y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (vis[xx][yy] == 1) continue;
                if (dfs(xx, yy, idx + 1)) return true;
            }
            vis[x][y] = false;
            return false;
        };

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dfs(i, j, 0)) 
                    return true;
            }
        }
        return false;
    }
};
int main()
{
    Solution AC;
    int n, m; cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    string str;
    while (cin >> str)
    {
        cout << (AC.exist(a, str) ? "YES" : "NO") << endl;
    }
    return 0;
}
/*
4 4
A B C E
S F C S 
A D E E
ABCCED
SEE
ABCB
*/