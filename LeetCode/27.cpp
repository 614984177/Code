#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        if (nums.empty()) return 0;
        int len = 0;
        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != val) nums[len++] = nums[i];
        return len;
    }
};
int main()
{
    Solution AC;
    int n, val;
    while (cin >> n >> val)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            v.emplace_back(x);
        }
        int len = AC.removeElement(v, val);
        for (int i = 0; i < len; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}
/*
4 3
3 2 2 3
8 2
0 1 2 2 3 0 4 2
*/