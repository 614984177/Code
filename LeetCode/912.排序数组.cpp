
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution 
{
public:
    vector<int> sortArray(vector<int>& nums)
    {
        Sort(nums, 0, nums.size());
        return nums;
    }

private:
    void partition(vector<int> &a, int L, int R, int &l, int &r)
    {
        int i = L, base = a[L + rand() % (R - L)];
        while (i < r)
        {
            if (a[i] < base) swap(a[i], a[l++]), i++;
            else if (a[i] > base) swap(a[i], a[--r]);
            else i++;
        }
    }

    void Sort(vector<int> &a, int L, int R)
    {
        if (L >= R) return ;
        int l = L, r = R;
        partition(a, L, R, l, r);
        Sort(a, L, l);
        Sort(a, r, R);
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> ans = AC.sortArray(a);
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    return 0;
}
/*
5
4 3 5 1 2
*/