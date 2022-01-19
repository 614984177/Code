#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
typedef long long LL;
int a[MAXN];
int main()
{
    for (int i = 1; i <= 4; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 5);
    int c = a[4] - a[1], b = a[4] - a[2], aa = a[4] - a[3];
    printf("%d %d %d\n", aa, b, c);
	return 0;
}
/*
3 6 5 4
*/