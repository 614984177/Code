#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, A, B, s[MAXN];
int main()
{
    scanf("%d%d%d", &n, &B, &A);
    for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
    int a = A, b = B, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 0)
        {
            if (a) a--;
            else if (b) b--;
            else break;
        }
        if (s[i] == 1)
        {
            if (a == A || (a > 0 && b == 0)) a--;
            else if (b) b--, a++;
            else break;
        }
        //printf("%d %d\n", a, b);
        ans = i;
    }
    printf("%d\n", ans);
    return 0;
}
/*
5 2 1
0 1 0 1 0
*/