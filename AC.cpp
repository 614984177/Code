#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int n, m;
map<int, int> odd, even;
int main()
{
    scanf("%d%d", &n, &m);
    int MAX1 = -1, MAX2 = -1, MAX3 = -1, MAX4 = -1;
    odd[MAX1] = odd[MAX2] = even[MAX3] = even[MAX4] = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x; scanf("%d", &x);
            if ((i + j) % 2)  
            {
                odd[x]++;
                if (odd[x] >= odd[MAX1]) MAX2 = MAX1, MAX1 = x;
                else if (odd[x] > odd[MAX2]) MAX2 = x;
            }   
            else 
            {
                even[x]++;
                if (even[x] >= even[MAX3]) MAX4 = MAX3, MAX3 = x;
                else if (even[x] > even[MAX4]) MAX4 = x;
            }

        }
    }
    int xxxx;
    if (MAX1 == MAX2) MAX2 = -1;
    if (MAX3 == MAX4) MAX4 = -1;
    int ans = n * m;
    if (MAX1 != MAX3) ans -= odd[MAX1] + even[MAX3];
    else 
    {
        if (MAX2 != -1 && MAX4 != -1) 
            ans -= max(odd[MAX1] + even[MAX4], even[MAX3] + odd[MAX2]);
        else if (MAX2 != -1)
            ans -= max(odd[MAX1], even[MAX3] + odd[MAX2]);
        else if (MAX4 != -1)
            ans -= max(even[MAX3], even[MAX4] + odd[MAX1]);
        else
            ans -= max(odd[MAX1], even[MAX3]);
    }
    printf("%d\n", ans);
    return 0;
}
/*
3 3
1 1 1
1 1 1
1 1 1
*/