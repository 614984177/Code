#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e5 + 5;
typedef long long LL;
int n;
char a[MAXN], b[MAXN];
vector<int> A[27], B[27];
int main()
{
    scanf("%d%s%s", &n, a, b);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != '?') A[a[i] - 'a'].push_back(i);
        else A[26].push_back(i);

        if (b[i] != '?') B[b[i] - 'a'].push_back(i);
        else B[26].push_back(i);
    }
    vector<pair<int, int> > ans;
    auto t1 = A[26].begin(), t2 = B[26].begin();
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < max(A[i].size(), B[i].size()); j++)
        {
            int x = -1, y = -1;
            if (j < A[i].size()) x = A[i][j];
            else if (t1 != A[26].end()) x = *t1, t1++;

            if (j < B[i].size()) y = B[i][j];
            else if (t2 != B[26].end()) y = *t2, t2++;

            if (x == -1 || y == -1) break;
            ans.emplace_back(x, y);
        }
    }
    while (t1 != A[26].end() && t2 != B[26].end())
    {
        ans.emplace_back(*t1, *t2);
        t1++, t2++;
    }
    printf("%d\n", ans.size());
    for (auto i : ans) printf("%d %d\n", i.first+1, i.second+1);
    return 0;
}
/*
10
code??????
??????test
*/