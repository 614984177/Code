#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int n;
char a[MAXN][MAXN];
bool change(int x, int y)
{
    if (a[x][y] == '.' && a[x - 1][y] == '.' && a[x + 1][y] == '.' 
    && a[x][y - 1] == '.' && a[x][y + 1] == '.')
    {
        a[x][y] = a[x - 1][y] = a[x + 1][y] = 
        a[x][y - 1] = a[x][y + 1] = '#';
        return true;
    }
    return false;
}
int main()
{
	scanf("%d", &n);
    memset(a, '#', sizeof(a));
    for (int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == '.')
            {
                if (!change(i + 1, j)) { printf("NO\n"); return 0; }
            }
        }
    }
    printf("YES\n");
	return 0;
}
/*
3
#.#
...
#.#
*/