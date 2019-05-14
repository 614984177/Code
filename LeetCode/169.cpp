#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int majorityElement(vector<int>& nums) 
    {
        int ans = nums[0], cnt = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == ans) cnt++;
            else cnt--;
            if (cnt == 0) ans = nums[i], cnt = 1;
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
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) cin >> v[i];
        cout << AC.majorityElement(v) << endl;
    }
    return 0;
}
/*
3
3 2 3
7
2 2 1 1 1 2 2
*/