#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
char s[MAXN];
int main()
{
    scanf("%d%s", &n, s + 1);
    for (int i = 0; i <= n; i++)
    {
        int t = i;
        for (int j = 1; j <= n; j++)
        {
            if (s[j] == '-') t--;
            else t++;
            if (t == -1) break;
        }
        if (t != -1) { printf("%d\n", t); break; }
    }
    return 0;
}
/*
3
---
*/