#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, ans[MAXN];
string s, t;
int main()
{
    cin >> n >> s >> t;
    int g = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] = t[i] - s[i] + g;
        g = 0;
        if (ans[i] < 0) ans[i] += 26, g = -1;
        if (i > 0 && (t[i - 1] - s[i - 1] + g) % 2) ans[i] += 26, g--;
        ans[i] /= 2;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] += (s[i] - 'a');
        if (i > 0) ans[i - 1] += ans[i] / 26;
        ans[i] %= 26;
    }
    for (int i = 0; i < n; i++) printf("%c", ans[i] + 'a');
    return 0;
}
/*
2
az
bf
5
jzokb
xiahb
*/