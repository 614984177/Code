#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int n, m, A[MAXN][MAXN], B[MAXN][MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &A[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &B[i][j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (A[i][j] != B[i][j])
            {
                bool flag;
                int x = i, y = j;
                while (x <= n && y >= 1 && A[x][y] != B[i][j]) x++, y--;
                if (x <= n && y >= 1 && A[x][y] == B[i][j]) swap(A[i][j], A[x][y]);
                else { printf("NO\n"); return 0; }
            }
        }
    }
    printf("YES\n");
    return 0;
}
/*
2 2
1 1
6 1
1 6
1 1
*/