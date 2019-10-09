#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int trap(vector<int>& height) 
    {
        int l = 0, r = height.size() - 1;
        int l_max = 0, r_max = 0, ans = 0;
        while (l < r)
        {
            if (height[l] < height[r])
            {
                if (height[l] >= l_max) l_max = height[l];
                else ans += l_max - height[l];
                l++;
            }
            else
            {
                if (height[r] >= r_max) r_max = height[r];
                else ans += r_max - height[r];
                r--;
            }
        }
        return ans;
    }
};

int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    cout << AC.trap(a) << endl;
    return 0;
}
/*
12
0 1 0 2 1 0 1 3 2 1 2 1
*/