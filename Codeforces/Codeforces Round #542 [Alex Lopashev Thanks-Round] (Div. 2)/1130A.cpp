#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int main()
{
    int n; scanf("%d", &n);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        int x; scanf("%d", &x);
        if (x > 0) a++;
        if (x < 0) b++;
    }
    if (a >= (n + 1) / 2) printf("1");
    else if (b >= (n + 1) / 2) printf("-1");
    else printf("0");
    return 0;
}
/*
5
10 0 -7 2 6
*/