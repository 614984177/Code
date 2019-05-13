#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for (int i = 0; i < n; i++) nums1[m + i] = nums2[i];
        sort(nums1.begin(), nums1.end());
    }
};
int main()
{
    Solution AC;
    int n, m;
    while (cin >> m >> n)
    {
        vector<int> a(m + n, 0), b(n, 0);
        for (int i = 0; i < m; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        AC.merge(a, m, b, n);
        for (int i = 0; i < m + n; i++) printf("%d ", a[i]);
        printf("\n");
    }
    return 0;
}
/*
3 3
1 2 3
2 5 6
*/