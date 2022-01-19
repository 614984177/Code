#include <bits/stdc++.h>
using namespace std;
const int MAXN = 55;
const int INF = 0x3f3f3f3f;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, r1, c1, r2, c2;
char a[MAXN][MAXN];
bool vis[MAXN][MAXN];
void BFS(int sx, int sy, vector<pair<int, int> >& v)
{
    memset(vis, 0, sizeof(vis));
    queue<pair<int, int> > Q;
    Q.push(make_pair(sx, sy)); vis[sx][sy] = true;
    while (!Q.empty())
    {
        auto u = Q.front(); Q.pop();
        v.push_back(u);
        for (int i = 0; i < 4; i++)
        {
            int xx = u.first + dx[i], yy = u.second + dy[i];
            if (xx <= 0 || yy <= 0 || xx > n || yy > n || vis[xx][yy] || a[xx][yy] == '1') continue;
            vis[xx][yy] = true;
            Q.push(make_pair(xx, yy));
        }
    }
}
int main()
{
    scanf("%d%d%d%d%d", &n, &r1, &c1, &r2, &c2);
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    vector<pair<int, int> > A, B;
    BFS(r1, c1, A);
    BFS(r2, c2, B);
    int ans = INF;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            int t = (A[i].first - B[j].first) * (A[i].first - B[j].first)
                    + (A[i].second- B[j].second) * (A[i].second - B[j].second);
            ans = min(ans, t);
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
5
1 1
5 5
00000
11110
00110
00110
00110
*/