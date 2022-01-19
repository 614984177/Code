#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105;
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN][MAXN];
int main()
{
    scanf("%s%s", a + 1, b + 1);
    int lena = strlen(a + 1), lenb = strlen(b + 1);
    dp[0][0][0] = 1;
    for (int i = 1; i <= lena; i++)
    {
        for (int j = 0; j <= lenb; j++)
        {
            for (int k = 0; k <= lena; k++)
            {
                if (!k && a[i] == b[j]) dp[i][j][k] |= dp[i - 1][j - 1][k];
                if (a[i] == '(' && k > 0) dp[i][j][k] |= dp[i - 1][j][k - 1];
                if (a[i] == ')') dp[i][j][k] |= dp[i - 1][j][k + 1];
            }
        }
    }
    if (dp[lena][lenb][0]) printf("Possible");
    else printf("Impossible");
    return 0;
}
/*
((())((())())())
(()(())())
*/
