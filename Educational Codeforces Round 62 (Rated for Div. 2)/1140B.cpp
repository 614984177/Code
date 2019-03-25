#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
char a[MAXN];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%s", &n, a);
        int l = 0, r = n - 1;
        while (a[l] != '>') l++;
        while (a[r] != '<') r--;
        printf("%d\n", min(l, n - r - 1));
    }
    return 0;
}
/*
3
2
<>
3
><<
1
>
*/