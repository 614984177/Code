#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int L = -1, R = nums.size(), i = 0, key = 1;
        while (i < R)
        {
            if (nums[i] < key) swap(nums[i], nums[++L]), i++;
            else if (nums[i] > key) swap(nums[i], nums[--R]);
            else i++;
        }
    }
};
int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> a(n, -1);
    for (int i = 0; i < n; i++) cin >> a[i];
    AC.sortColors(a);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    return 0;
}
/*
6
2 0 2 1 1 0
*/