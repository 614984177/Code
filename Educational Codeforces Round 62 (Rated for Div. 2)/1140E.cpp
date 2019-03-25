#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
typedef long long LL;
const int MOD = 998244353;
int n, k;
LL dp[MAXN][2];
vector<int> odd, even;
LL qpow(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b&1) res = res * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return res;
}
LL work(vector<int>& a)
{
    for (int i = 1; i < a.size(); i++)
        if (a[i] == a[i - 1] && a[i] != -1) return 0;
    LL ans = 1;
    int l = 0, r = 0;
    while (r < a.size())
    {
        while (l < a.size() && a[l] != -1) l++;
        r = l;
        while (r < a.size() && a[r] == -1) r++;
        if (l == 0 && r == a.size()) ans = k * qpow(k - 1, r - l - 1) % MOD;
        else if (l == 0 || r == a.size()) ans = ans * qpow(k - 1, r - l) % MOD;
        else if (a[l - 1] == a[r]) ans = ans * dp[r - l][1] % MOD;
        else ans = ans * dp[r - l][0] % MOD;
        //cout << l << " " << r << endl;
        l = r;
    }
    return ans;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int x; scanf("%d", &x);
        if (i & 1) odd.push_back(x);
        else even.push_back(x);
    }
    dp[1][0] = k - 2, dp[1][1] = k - 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][1] + (k - 2) * dp[i - 1][0]) % MOD;
        dp[i][1] = (k - 1) * dp[i - 1][0] % MOD;
    }
    printf("%lld\n", work(odd) * work(even) % MOD);
    return 0;
}
/*
2 3
-1 -1
*/