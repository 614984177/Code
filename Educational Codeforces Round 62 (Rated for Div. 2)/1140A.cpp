#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    int MAX = 0, cnt = 0;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
        MAX = max(MAX, a[i]);
        cnt += (MAX == i);
    }
    printf("%d\n", cnt);
    return 0;
}
/*
9
1 3 3 6 7 6 8 8 9
*/