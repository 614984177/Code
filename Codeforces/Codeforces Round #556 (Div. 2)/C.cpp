#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
int n;
int main()
{
	scanf("%d", &n);
    int one = 0, two = 0;
    for (int i = 1; i <= n; i++)
    {
        int x; scanf("%d", &x);
        if (x == 1) one++;
        else two++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (cnt == 2 && one) cnt += 1, one--, printf("1 ");
        else if (two) cnt += 2, two--, printf("2 "); 
        else cnt += 1, one--, printf("1 ");
    }
	return 0;
}
/*
5
1 2 1 2 1
*/