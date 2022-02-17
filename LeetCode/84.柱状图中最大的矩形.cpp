#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> st;
        st.push(-1);
        for (int i = 0; i < heights.size(); i++) {
            while (st.top() != -1 && heights[st.top()] > heights[i]) {
                int t = st.top(); st.pop();
                ans = max(ans, heights[t] * (i - st.top() - 1));
            }
            st.push(i);
        }
        while (st.top() != -1) {
            int t = st.top(); st.pop();
            ans = max(ans, heights[t] * (int(heights.size()) - st.top() - 1));
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
    cout << AC.largestRectangleArea(a) << endl;
    return 0;
}
/*
6
2 1 5 6 2 3
2
2 4
*/