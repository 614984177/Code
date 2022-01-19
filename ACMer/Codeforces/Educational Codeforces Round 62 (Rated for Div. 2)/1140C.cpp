#include<bits/stdc++.h>
using namespace std;
#define X first 
#define Y second
const int MAXN = 3e5 + 5;
typedef long long LL;
int n, k;
pair<int, int> a[MAXN];
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d%d", &a[i].X, &a[i].Y);
    sort(a, a + n, [](pair<int, int> a, pair<int, int> b){ return a.Y > b.Y;  });
    LL ans = 0, sum = 0;
    priority_queue<int, vector<int>, greater<int>> Q;
    for (int i = 0; i < n; i++)
    {
        sum += a[i].X;
        Q.push(a[i].X);
        if (Q.size() > k) sum -= Q.top(), Q.pop();
        ans = max(ans, a[i].Y * sum);
    }
    printf("%lld\n", ans);
    return 0;
}
/*
4 3
4 7
15 1
3 6
6 8
*/