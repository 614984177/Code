#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
string s;
int main()
{
    cin >> n >> s;
    int MAX = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] >= s[MAX]) MAX = i;
        else { printf("YES\n%d %d\n", MAX + 1, i + 1); return 0; }
    }
    printf("NO\n");
    return 0;
}
/*
7
abacaba
*/