#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
        return *max_element(dp.begin(), dp.end());
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> a;
        for (int i = 1; i <= n; i++)
        {
            int x; scanf("%d", &x);
            a.emplace_back(x);
        }
        cout << AC.maxSubArray(a) << endl;
    }
    return 0;
}
/*
9
-2 1 -3 4 -1 2 1 -5 4
*/