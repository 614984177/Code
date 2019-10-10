#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
    struct Node
    {
        int x, y, h;
        Node () {}
        Node (int x, int y, int h): x(x), y(y), h(h) {}
        bool operator > (const Node &rhs) const { return rhs.h < h; }
    };
    
public:
    int trapRainWater(vector<vector<int>>& heightMap)
    {
        if (heightMap.empty()) return 0;
        int n = heightMap.size(), m = heightMap[0].size();
        const int dx[] = {0, 0, 1, -1};
        const int dy[] = {1, -1, 0, 0};
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        priority_queue<Node, vector<Node>, greater<Node>> PQ;
        for (int i = 0; i < m; i++) 
        {
            vis[0][i] = true, PQ.emplace(0, i, heightMap[0][i]);
            vis[n - 1][i] = true, PQ.emplace(n - 1, i, heightMap[n - 1][i]);
        }
        for (int i = 0; i < n; i++) 
        {
            vis[i][0] = true, PQ.emplace(i, 0, heightMap[i][0]);
            vis[i][m - 1] = true, PQ.emplace(i, m - 1, heightMap[i][m - 1]);
        }
        int ans = 0;
        while (!PQ.empty())
        {
            Node u = PQ.top(); PQ.pop();
            for (int i = 0; i < 4; i++)
            {
                int xx = u.x + dx[i], yy = u.y + dy[i];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (vis[xx][yy]) continue;
                vis[xx][yy] = true;
                ans += max(0, u.h - heightMap[xx][yy]);
                PQ.emplace(xx, yy, max(u.h, heightMap[xx][yy]));
            }
        }
        return ans;
    }
};

int main()
{
    Solution AC;
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
        }
    }
    cout << AC.trapRainWater(a) << endl;
    return 0;
}
/*
3 6
1 4 3 1 3 2
3 2 1 3 2 4
2 3 3 2 3 1
5 4
12 13 1 12
13 4 13 12
13 8 10 12
12 13 12 12
13 13 13 13
*/