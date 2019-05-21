#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int firstMissingPositive(vector<int>& nums) 
    {
        for (int i = 0; i < nums.size(); i++)
        {
            while (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1) return i + 1;
        return nums.size() + 1;
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
        cout << AC.firstMissingPositive(a) << endl;
    }
    return 0;
}
/*
3
1 2 0
4
3 4 -1 1
5
7 8 9 11 12
*/