#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int MAX = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (MAX < i) break;
            MAX = max(MAX, i + nums[i]);
        }
        return MAX >= nums.size();
    }
};
int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << AC.canJump(a) << endl;
    return 0;
}
/*
5
2 3 1 1 4
5
3 2 1 0 4
*/