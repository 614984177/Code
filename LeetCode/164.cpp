#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
class Solution 
{
public:
    int maximumGap(vector<int>& nums) 
    {
        if (nums.size() < 2)
            return 0;
        int MIN = *min_element(nums.begin(), nums.end());
        int MAX = *max_element(nums.begin(), nums.end());
        int block_size = max(1, (MAX - MIN) / int(nums.size()) + 1);
        vector<pair<int, int>> a(nums.size() + 1, make_pair(INT_MAX, INT_MIN));
        for (const auto &i : nums)
        {
            int idx = (i - MIN) / block_size; 
            a[idx].first = min(a[idx].first, i);
            a[idx].second = max(a[idx].second, i);
        }
        int ans = -1, pre = a[0].first;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i].first == INT_MAX) continue;
            ans = max(ans, a[i].first - pre);
            pre = a[i].second;
        }
        return ans;
    }
};
int main()
{
    Solution AC;
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        v.emplace_back(x);
    }
    cout << AC.maximumGap(v) << endl;
    return 0;
}
/*
4
3 6 1 9
*/