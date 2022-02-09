//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 15;
int n, v, dp[100005];
pair<int, int> a[MAXN];
void ZeroOne_Backpack(int cost, int value) // 01背包
{
    for (int i = v; i >= cost; i--)
        dp[i] = max(dp[i], dp[i - cost] + value);
}
void Complete_Backpack(int cost, int value) //完全背包
{
    for (int i = cost; i <= v; i++)
        dp[i] = max(dp[i], dp[i - cost] + value);
}
void Mul_Backpack(int x) //多重背包
{
    int num = a[x].first, cost = a[x].second, value = a[x].second;
    if (num * cost <= v) // 能够放的下
    {
        int i = 1;
        while (i < num)
        {
            ZeroOne_Backpack(cost * i, value * i);
            num -= i;
            i *= 2;
        }
        ZeroOne_Backpack(num * cost, num * value);
    }
    else
        Complete_Backpack(cost, value); //完全
}
int main()
{
    while (~scanf("%d%d", &v, &n))
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
            scanf("%d%d", &a[i].first, &a[i].second);
        for (int i = 0; i < n; i++)
            Mul_Backpack(i);
        printf("%d\n", dp[v]);
    }
    return 0;
}
/*
735 3  4 125  6 5  3 350
633 4  500 30  6 100  1 5  0 1
735 0
0 3  10 100  10 50  10 10
*/