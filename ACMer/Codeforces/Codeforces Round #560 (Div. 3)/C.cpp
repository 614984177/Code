#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n;
char s[MAXN];
int main()
{
    scanf("%d%s", &n, s + 1);
    int k = 0, i = 1, j = 1;
    string ans;
    while (i <= n)
    {
        j = i + 1;
        while (j <= n && s[i] == s[j]) k++, j++;
        if (j <= n && s[i] != s[j]) ans += s[i], ans += s[j];
        else k++;
        i = j + 1;
    }
    printf("%d\n%s\n", k, ans.c_str());
    return 0;
}
/*
4
good
*/

