#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const double PI = acos(-1);
int n, r;
int main()
{
    scanf("%d%d", &n, &r);
    double s = sin(PI / n);
    double x = s * r / (1 - s);
    printf("%.7f", x);
    return 0;
}
/*
3 1
*/