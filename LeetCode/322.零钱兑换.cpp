#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, 0x3f3f3f3f);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        return dp[amount] >= 0x3f3f3f3f ? -1 : dp[amount];
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n, amount;
    while (cin >> amount >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        cout << AC.coinChange(a, amount) << endl;
    }
    return 0;
}
/*
11 3
1 2 5
2 1
3
0 1
1
*/