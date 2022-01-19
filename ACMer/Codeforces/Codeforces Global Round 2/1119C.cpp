#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int n, m, r[MAXN], c[MAXN], A[MAXN][MAXN], B[MAXN][MAXN];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &B[i][j]);
            if (A[i][j] != B[i][j]) r[i]++, c[j]++;
        }
    }
    for (int i = 0; i < n; i++) 
        if (r[i] % 2) { printf("NO\n"); return 0; }
    for (int i = 0; i < m; i++) 
        if (c[i] % 2) { printf("NO\n"); return 0; }
    printf("YES\n");
    return 0;
}
/*
3 3
0 1 0
0 1 0
1 0 0
1 0 0
1 0 0
1 0 0
*/