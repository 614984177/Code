#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
string s;
int main()
{
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n - 10; i++)
    {
        if (s[i] == '8') cnt++;
        else cnt--;
    }
    if (cnt > 0) printf("YES\n");
    else printf("NO\n");
    return 0;
}
/*
13
8380011223344
*/