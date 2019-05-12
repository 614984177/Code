#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, L, cnt, s[MAXN];
bool dfs(int cur)
{
    if (cnt++ == n)
    {
        for (int i = 0; i < cur; i++) 
        {
            printf("%c", s[i] + 'A');
            if (i != cur - 1 && i % 4 == 3) printf("%c", i == 16 * 4 - 1 ? '\n' : ' ');
        }
        printf("\n%d\n", cur);
        return 0;
    }
    for (int i = 0; i < L; i++)
    {
        s[cur] = i;
        bool ok = true;
        for (int j = 1; j * 2 <= cur + 1; j++)
        {
            bool equal = true;
            for (int k = 0; k < j; k++)
                if (s[cur - k] != s[cur - k - j]) { equal = false; break; }
            if (equal) { ok = 0; break; }
        }
        if (ok)
        {
            if (!dfs(cur + 1)) return 0;
        }
    }
    return 1;
}
int main()
{
    while (scanf("%d%d", &n, &L) != EOF && (n + L))
    {
        cnt = 0;
        dfs(0);
    }
    return 0;
}
/*
7 3
30 3
0 0
*/