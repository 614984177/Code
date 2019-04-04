#include<bits/stdc++.h>
using namespace std;
const int MAXN = 505;

int main()
{
    int h1, h2, m1, m2;
    scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);
    printf("%02d:%02d\n", (h1 + h2) / 2, (m1 + m2) / 2);
    return 0;
}
/*
10:00
11:00
*/