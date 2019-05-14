#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        const int INF = 0x3f3f3f3f;
        if (nums1.size() > nums2.size()) nums1.swap(nums2);
        int n = nums1.size(), m = nums2.size();
        int l = 0, r = n;
        while (l <= r)
        {
            int i = (l + r) / 2, j = (n + m + 1) / 2 - i;
            if (i < n && nums1[i] < nums2[j - 1]) l = i + 1;
            else if (i > 0 && nums2[j] < nums1[i - 1]) r = i - 1;
            else
            {
                int MAXL = -INF, MINR = INF;
                if (i - 1 >= 0) MAXL = max(MAXL, nums1[i - 1]);
                if (j - 1 >= 0) MAXL = max(MAXL, nums2[j - 1]);
                if (i < n) MINR = min(MINR, nums1[i]);
                if (j < m) MINR = min(MINR, nums2[j]);
                return (n + m) % 2 ? 1.0 * MAXL : 1.0 * (MAXL + MINR) / 2;
            }
        }
        return 0.0;
    }
};
int main()
{
    Solution AC;
    int n, m;
    while (cin >> n >> m)
    {
        vector<int> a, b;
        for (int i = 1; i <= n; i++)
        {
            int x; scanf("%d", &x);
            a.emplace_back(x);
        }
        for (int i = 1; i <= m; i++)
        {
            int x; scanf("%d", &x);
            b.emplace_back(x);
        }
        cout << AC.findMedianSortedArrays(a, b) << endl;
    }
    return 0;
}
/*
2 1
1 3
2
2 2
1 2
3 4
*/