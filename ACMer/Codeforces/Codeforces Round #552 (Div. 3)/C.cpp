#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int idx[8] = {0, 1, 2, 3, 1, 3, 2, 1};
int a[4], b[4];
int main()
{
    scanf("%d%d%d", &a[1], &a[2], &a[3]);
    int ans = 0;
    for (int i = 1; i <= 7; i++)
    {
        b[1] = a[1], b[2] = a[2], b[3] = a[3];
        int j = i, MAX = min(b[1] / 3, min(b[2] / 2, b[3] / 2));
        b[1] -= MAX * 3, b[2] -= MAX * 2, b[3] -= MAX * 2;
        MAX *= 7;
        while (b[1] || b[2] || b[3])
        {
            if (b[idx[j]] == 0) break;
            b[idx[j]]--, MAX++;
            j = j % 7 + 1;
        } 
        ans = max(ans, MAX);
    }
    printf("%d\n", ans);
    return 0;
}
/*
2 1 1
*/