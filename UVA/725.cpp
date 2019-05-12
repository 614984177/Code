#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
bool check(int a, int b)
{
    if (a > 99999) return false;
    set<int> s;
    for (int i = 1; i <= 5; i++)
    {
        s.insert(a % 10);
        s.insert(b % 10);
        a /= 10, b /= 10;
    }
    return s.size() == 10;
}
int main()
{
    bool has_out = false;
	while (scanf("%d", &n) && n)
    {
        if (has_out) printf("\n");
        has_out = true;
        bool flag = false;
        for (int i = 0; i <= 99999; i++)
        {
            if (check(i * n, i))
            {
                flag = true;
                printf("%05d / %05d = %d\n", i * n, i, n);
            }
        }
        if (!flag) printf("There are no solutions for %d.\n", n);
    }
	return 0;
}
/*
50
29
2
46
44
80
80
75
3
27
14
33
46
67
5
79
27
73
3
60
74
66
25
14
74
26
17
23
27
47
0
*/