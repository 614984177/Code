#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        return quickSelect(nums, nums.size() - k, 0, nums.size());
    }
private:
    void partition(vector<int> &a, int L, int R, int &l, int &r)
    {
        int i = l, base = a[L + rand() % (R - L)];
        while (i < r)
        {
            if (a[i] < base) swap(a[i], a[l++]), i++;
            else if (a[i] > base) swap(a[i], a[--r]);
            else i++;
        }
    }
    int quickSelect(vector<int> &a, int k, int L, int R)
    {
        if (L >= R) return -1;
        int l = L, r = R;
        partition(a, L, R, l, r);
        if (k < l) return quickSelect(a, k, L, l);
        if (k >= r) return quickSelect(a, k, r, R);
        return a[k];
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n, k;
    while (cin >> n >> k)
    {
        vector<int> a(n, 0);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << AC.findKthLargest(a, k) << endl;
    }
    return 0;
}
/*
6 2
3 2 1 5 6 4
*/