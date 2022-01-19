#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long LL;
int prime[MAXN], tot, phi[MAXN];
bool vis[MAXN];
void GetPrime(int n)
{
    vis[0] = vis[1] = 1; 
    phi[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i]) prime[++tot] = i, phi[i] = i - 1;
        for (int j = 1; j <= tot && i * prime[j] <= n; j++)
        {
            vis[i * prime[j]] = true;
            if (i % prime[j]) phi[i * prime[j]] = phi[i] * (prime[j] - 1);
            else 
            {
                phi[i * prime[j]] = phi[i] * prime[j];
                break;
            }
        }
    }
}
int n;
LL ans[MAXN];
int main()
{
    scanf("%d", &n);
    GetPrime(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            //小于等于n且与n互质的数字的和φ(n)*n/2，特殊的φ(1) = 1
            ans[j] += 1LL * phi[i] * i / 2 + (i == 1);
        }
    }
    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
    return 0;
}
/*
6
*/