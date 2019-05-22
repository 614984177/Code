#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> ans(nums.size());
        ans.back() = nums.back();
        for (int i = nums.size() - 2; i >= 0; i--)
            ans[i] = ans[i + 1] * nums[i];
        int pre = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + 1 < nums.size()) ans[i] = ans[i + 1] * pre;
            else ans[i] = pre;
            pre *= nums[i];
        }
        return ans;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> ans = AC.productExceptSelf(a);
        for (auto i : ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}
/*
4
1 2 3 4
*/