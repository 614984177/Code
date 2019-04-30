#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, Q, nex[MAXN][30], len[5], dp[255][255][255];
char str[MAXN], s[5][255];
void init()
{
    memset(nex, INF, sizeof(nex));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
            nex[i][j] = nex[i + 1][j];
        nex[i][str[i + 1] - 'a'] = i + 1;
    }
}
int main()
{
    scanf("%d%d%s%*c", &n, &Q, str + 1);
    init();
    while (Q--)
    {
        char op, y; int x;
        scanf("%c %d", &op, &x);
        if (op == '+')
        {
            scanf(" %c", &y);
            len[x]++, s[x][len[x]] = y;
            for (int i = (x == 1 ? len[1] : 0); i <= len[1]; i++)
            {
                for (int j = (x == 2 ? len[2] : 0); j <= len[2]; j++)
                {
                    for (int k = (x == 3 ? len[3] : 0); k <= len[3]; k++)
                    {
                        dp[i][j][k] = n + 1;
                        if (i) dp[i][j][k] = min(dp[i][j][k], nex[dp[i - 1][j][k]][s[1][i] - 'a']);
                        if (j) dp[i][j][k] = min(dp[i][j][k], nex[dp[i][j - 1][k]][s[2][j] - 'a']);
                        if (k) dp[i][j][k] = min(dp[i][j][k], nex[dp[i][j][k - 1]][s[3][k] - 'a']);
                    }
                }
            }
        }
        else if (op == '-') len[x]--;
        
        getchar();
        //printf("%c %d %c\n", op, x, y);
        if (dp[len[1]][len[2]][len[3]] <= n) printf("YES\n"); 
        else printf("NO\n");
    }
    return 0;
}
/*
6 8
abdabc
+ 1 a
+ 1 d
+ 2 b
+ 2 c
+ 3 a
+ 3 b
+ 1 c
- 2 
*/