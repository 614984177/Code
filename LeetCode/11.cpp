#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int maxArea(vector<int>& height) 
    {
        int l = 0, r = height.size() - 1, ans = 0;
        while (l < r)
        {
            ans = max(ans, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
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
        cout << AC.maxArea(a) << endl;
    }
    return 0;
}
/*
9
1 8 6 2 5 4 8 3 7
*/