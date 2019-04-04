#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2005;
int n, m;
int main()
{
    scanf("%d%d", &n, &m);
    if (m % n) { printf("-1"); return 0; }
    m /= n;
    int ans = 0;
    while (m % 2 == 0) ans++, m /= 2;
    while (m % 3 == 0) ans++, m /= 3;
    if (m != 1) printf("-1");
    else printf("%d\n", ans);
    return 0;
}
/*
7 7
*/