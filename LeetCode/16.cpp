#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
        const int INF = 0x3f3f3f3f;
        sort(nums.begin(), nums.end());
        int MIN = INF, ans = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            int l = i + 1, r = nums.size() - 1, k = target - nums[i];
            while (l < r)
            {
                int x = nums[i] + nums[l] + nums[r];
                if (MIN > abs(target - x))
                {
                    MIN = abs(target - x);
                    ans = x;
                }
                if (nums[l] + nums[r] < k) l++;
                else if (nums[l] + nums[r] > k) r--;
                else return ans;
            }
            l = i + 1, r = nums.size() - 1, k = target - nums[i];
            while (l < r)
            {
                int x = nums[i] + nums[l] + nums[r];
                if (MIN > abs(target - x))
                {
                    MIN = abs(target - x);
                    ans = x;
                }
                if (nums[l] + nums[r] < k) l++;
                else if (nums[l] + nums[r] > k) r--;
                else return ans;
            }
        }
        return ans;
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
        cout << AC.threeSumClosest(a, k) << endl;
    }
    return 0;
}
/*
4 1
-1 2 1 -4
*/