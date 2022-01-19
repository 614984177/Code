#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int MAX = -1, MIN = 1e9 + 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > MAX && (a[i] < a[i + 1] || a[i] >= MIN))
            MAX = a[i], a[i] = 0;
        else if (a[i] < MIN)
            MIN = a[i], a[i] = 1;
        else { printf("NO\n"); return 0; }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
/*
9
5 1 3 6 8 2 9 0 10
*/