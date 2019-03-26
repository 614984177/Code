#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
const int MAXN = 1e3 + 5;
int x, y, cnt[MAXN];
pair<int, int> a[MAXN];
bool vis[MAXN][MAXN];
void Move(int ex, int ey)
{
    while (x != ex || y != ey)
    {
        if (x < ex && vis[x + 1][y] == 0) x++;
        else if (x > ex && vis[x - 1][y] == 0) x--;
        if (y < ey && vis[x][y + 1] == 0) y++;
        else if (y > ey && vis[x][y - 1] == 0) y--;
        printf("%d %d\n", x, y);
        fflush(stdout);
        int k, xx, yy; scanf("%d%d%d", &k, &xx, &yy);
        if (k == -1) break;
        vis[a[k].X][a[k].Y] = 0;
        a[k] = make_pair(xx, yy);
        vis[a[k].X][a[k].Y] = 1;
    }
}
int main()
{
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= 666; i++)
    {
        scanf("%d%d", &a[i].X, &a[i].Y);
        vis[a[i].X][a[i].Y] = 1;
    }
    Move(500, 500);
    for (int i = 1; i <= 999; i++)
    {
        for (int j = 1; j <= 999; j++)
        {
            if (!vis[i][j]) continue;
            if (i < x && j < y) cnt[0]++;
            if (i < x && j > y) cnt[1]++;
            if (i > x && j < y) cnt[2]++;
            if (i > x && j > y) cnt[3]++;
        }
    }
    if (cnt[0] <= 166) Move(999, 999);
    else if (cnt[1] <= 166) Move(999, 1);
    else if (cnt[2] <= 166) Move(1, 999);
    else Move(1, 1);
    return 0;
}