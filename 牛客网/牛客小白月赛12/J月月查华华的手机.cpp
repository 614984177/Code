#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
char s[MAXN];
int a[MAXN][26];
int main()
{
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = 0; j < 26; j++)
            a[i][j] = a[i + 1][j];
        a[i][s[i + 1] - 'a'] = i + 1;
    }
    int Q; scanf("%d", &Q);
    while (Q--)
    {
        scanf("%s", s + 1);
        int idx = 0, len = strlen(s + 1);
        for (int i = 1; i <= len; i++)
        {
            if (a[idx][s[i] - 'a']) idx = a[idx][s[i] - 'a'];
            else { idx = -1; break; }
        }
        if (idx != -1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
/*
noiauwfaurainairtqltqlmomomo
8
rain
air
tql
ntt
xiaobai
oiiiooo
orzcnzcnznb
ooooo
*/