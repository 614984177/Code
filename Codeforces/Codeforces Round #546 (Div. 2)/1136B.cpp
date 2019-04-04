#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, k;
int main()
{
    scanf("%d%d", &n, &k);
    printf("%d\n", 3 * n + min(k - 1, n - k));
    return 0;
}
/*
2 2
*/