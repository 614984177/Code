#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    int findPeakElement(vector<int>& nums) 
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (m == 0 || m == nums.size() || nums[m - 1] < nums[m]) l = m + 1;
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