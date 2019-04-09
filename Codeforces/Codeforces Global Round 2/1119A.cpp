#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int l = 1, r = n;
    while (a[l] == a[n]) l++;
    while (a[r] == a[1]) r--;
    printf("%d\n", max(n - l, r - 1));
    return 0;
}
/*
5
1 2 3 2 3
*/