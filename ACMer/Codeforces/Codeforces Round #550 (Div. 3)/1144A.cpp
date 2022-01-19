#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
string solve(string s)
{
    sort(s.begin(), s.end());
    for (int i = 1; i < s.size(); i++)
        if (s[i] != s[i - 1] + 1) return "No";
    return "Yes";
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        string s; cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
/*
8
fced
xyz
r
dabcef
az
aa
bad
babc
*/