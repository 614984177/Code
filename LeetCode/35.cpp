#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int l = 0, r = nums.size();
        while (l < r)
        {
            int m = l + (r - l) / 2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        return l;
    }
};
int main()
{
    Solution AC;
    int n, key;
    while (cin >> n >> key)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            int x; scanf("%d", &x);
            v.emplace_back(x);
        }
        cout << AC.searchInsert(v, key) << endl;
    }
    return 0;
}
/*
4 5
1 3 5 6
4 2
1 3 5 6
4 7
1 3 5 6
4 0
1 3 5 6
*/