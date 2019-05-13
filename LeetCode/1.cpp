#include <bits/stdc++.h>
using namespace std;
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> ans;
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                ans.emplace_back(mp.at(target - nums[i]));
                ans.emplace_back(i);
                return ans;
            }
            mp.emplace(nums[i], i);
        }
        return ans;
    }
};
int main()
{
    Solution AC;
    int n, k;
    while (~scanf("%d%d", &n, &k))
    {
        vector<int> a;
        while (n--)
        {
            int x; scanf("%d", &x);
            a.emplace_back(x);
        }
        vector<int> ans = AC.twoSum(a, k);
        for (auto i : ans) printf("%d ", i);
        printf("\n");
    }
    return 0;
}
/*
4 9
2 7 11 15
*/