#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int lmax = height[0], rmax = height.back(), l = 0, r = height.size() - 1, ans = 0;
        while (l < r) {
            if (height[l] <= height[r]) {
                if (height[l] > lmax) lmax = height[l];
                else ans += lmax - height[l];
                l++;
            }
            else {
                if (height[r] > rmax) rmax = height[r];
                else ans += rmax - height[r];
                r--;
            } 
        }
        return ans;
    }
};
// @lc code=end

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