#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, v;
int main()
{
    scanf("%d%d", &n, &v);
    if (v > n-1) { printf("%d\n", n-1); return 0; }
    int t = n-1-v;
    printf("%d\n", v + (2 + 2+t-1) * t / 2);
    return 0;
}
/*
4 2
*/