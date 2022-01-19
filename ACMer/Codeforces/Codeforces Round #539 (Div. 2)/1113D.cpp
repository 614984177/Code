#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
string s;
int a[MAXN];
int solveEven(const string& s)
{
    if (s.size() % 2 == 1) return 2;
    string L = s.substr(0, s.size() / 2);
    string R = s.substr(s.size() / 2, s.size() / 2);
    if (L != R) return 1;
    return solveEven(L);
}
int main()
{
    cin >> s;
    for (auto c : s) a[c - 'a']++;
    if (s.size() < 3 || *max_element(a, a + 26) >= s.size() - 1)
    {
        printf("Impossible\n");
        return 0;
    }
    printf("%d\n", s.size() % 2 == 0 ? solveEven(s) : 2);
    return 0;
}
/*
nolon
*/