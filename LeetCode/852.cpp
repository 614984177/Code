#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int peakIndexInMountainArray(vector<int>& A) 
    {
        int l = 1, r = A.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (A[m - 1] < A[m]) l = m + 1;
            else r = m;
        }
        return l - 1;
    }
};
int n;
int main()
{
    Solution AC;
    while (cin >> n)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            v.emplace_back(x);
        }
        cout << AC.findPeakElement(v) << endl;
    }
    return 0;
}
/*
4
1 2 3 1
7
1 2 1 3 5 6 4
*/