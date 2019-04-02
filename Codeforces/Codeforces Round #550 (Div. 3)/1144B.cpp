#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n, sum1, sum2;
vector<int> odd, even;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        int a; scanf("%d", &a);
        if (a%2) sum1 += a, odd.push_back(a);
        else sum2 += a, even.push_back(a);
    }
    sort(odd.begin(), odd.end());
    sort(even.begin(), even.end());
    int i = odd.size() - 1, j = even.size() - 1;
    if (i < j) sum2 -= even[j--];
    if (i > j) sum1 -= odd[i--];
    while (i >= 0 && j >= 0)
    {
        sum2 -= even[j--];
        sum1 -= odd[i--];
    }
    printf("%d\n", i != -1 ? sum1 : sum2);
    return 0;
}
/*
5
1 5 7 8 2
*/