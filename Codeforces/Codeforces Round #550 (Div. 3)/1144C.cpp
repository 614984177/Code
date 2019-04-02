#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int n, a[MAXN];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 2; i < n; i++)
    {
        if (a[i] == a[i - 1] && a[i - 1] == a[i - 2])
        {
            printf("NO\n"); 
            return 0; 
        }
    }
    printf("YES\n");
    vector<int> A, B;
    A.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1]) A.push_back(a[i]);
        else B.push_back(a[i]);
    }
    printf("%d\n", A.size());
    for (auto i : A) printf("%d ", i);
    printf("\n%d\n", B.size());
    for (int i = B.size() - 1; i >= 0; i--) printf("%d ", B[i]);
    return 0;
}
/*
7
7 2 7 3 3 1 4
*/