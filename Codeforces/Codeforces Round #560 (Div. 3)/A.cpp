#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, y, x;
string a;
int main()
{
    cin >> n >> y >> x >> a;
    int ans = 0;
    for (int i = n - 1; i >= n - y; i--)
    {
        if (n - i - 1 == x) { ans += (a[i] == '0'); continue; }
        if (a[i] == '1') ans++;
    }
    printf("%d\n", ans);
    return 0;
}
/*
11 5 2
11010100101
*/