#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int search(vector<int>& nums, int target) 
    {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[l] <= nums[m])
            {
                if (nums[l] <= target && target <= nums[m]) r = m;
                else l = m + 1;
            }
            else
            {
                if (nums[m] < target && target <= nums[r]) l = m + 1;
                else r = m;
            }
        }
        return nums[l] == target ? l : -1;
    }
};
int main()
{
    Solution AC;
    int n, k;
    while (cin >> n >> k)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << AC.search(a, k) << endl;
    }
    return 0;
}
/*
7 0
4 5 6 7 0 1 2
*/