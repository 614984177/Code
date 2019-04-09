#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
const int INF = 0x3f3f3f3f;
int n, h, a[MAXN];
bool check(int n)
{
    long long cnt = 0;
    vector<int> v;
    for (int i = 0; i < n; i++) v.push_back(a[i]);
    sort(v.begin(), v.end());
    int s = 0;
    if (n%2) cnt = v[s++];
    for (int i = s; i < n; i += 2)
        cnt += max(v[i], v[i + 1]);
    return cnt <= h;
}
int main()
{
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    a[n] = INF;
    for (int i = 1; i <= n + 1; i++)
    {
        if (!check(i)) 
        { 
            printf("%d\n", i - 1);
            break; 
        }
    }
    return 0;
}
/*
5 7
2 3 5 4 1
*/