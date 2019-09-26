#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int> ans;
        //lower_bound
        int l = 0, r = nums.size();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        if (l != nums.size() && nums[l] == target) ans.emplace_back(l);
        else ans.emplace_back(-1);
        //upper_bound
        l = 0, r = nums.size();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] <= target) l = m + 1;
            else r = m;
        }
        if (l != 0 && nums[l - 1] == target) ans.emplace_back(l - 1);
        else ans.emplace_back(-1);
        return ans;
    }
};
int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans = AC.searchRange(a, 8);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
/*
6
5 7 7 8 8 10
*/