#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), a[i + n] = a[i];
    int MAX = 0, cnt = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (a[i] == 1) cnt++;
        else cnt = 0;
        MAX = max(MAX, cnt);
    }
    printf("%d\n", MAX);
    return 0;
}
/*
5
1 0 1 0 1
*/