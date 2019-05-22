#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, a[MAXN];
void partition(int l, int r, int base, int &L, int &R)
{
    int i = l;
    while (i < R)
    {
        if (a[i] < base) swap(a[++L], a[i]), i++;
        else if (a[i] > base) swap(a[--R], a[i]);
        else i++;
    }
    return ;
}
void Sort(int l, int r)
{
    if (l >= r) return ;
    int base = a[l + rand() % (r - l + 1)];
    int L = l - 1, R = r + 1;
    partition(l, r, base, L, R);
    Sort(l, L);
    Sort(R, r);
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    Sort(0, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
/*
5
4 2 4 5 1
*/