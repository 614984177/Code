#include <bits/stdc++.h>
using namespace std;
const int MAXV = 1e6;
int k;
int main()
{
    scanf("%d", &k);
    vector<int> ans(1, -1);
    int s = -1, n = 1; // n*s - (n-1)*(s-1) = s-n+1
    while (s - n + MAXV < k)
    {
        s += MAXV;
        n++;
        ans.push_back(MAXV);
    }
    ans.push_back(k - s + n);
    printf("%d\n", n + 1);
    for (auto i : ans) printf("%d ", i);
    return 0;
}
/*
8
*/