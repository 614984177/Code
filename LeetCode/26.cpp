#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int removeDuplicates(vector<int>& nums) 
    {
        if (nums.empty()) return 0;
        int len = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[len]) nums[++len] = nums[i];
        return ++len;
    }
};
int main()
{
    Solution AC;
    int n;
    while (cin >> n)
    {
        vector<int> v;
        for (int i = 1; i <= n; i++)
        {
            int x; cin >> x;
            v.emplace_back(x);
        }
        int len = AC.removeDuplicates(v);
        for (int i = 0; i < len; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}
/*
3
1 1 2
10
0 0 1 1 1 2 2 3 3 4
*/