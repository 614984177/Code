#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start
class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a%b);
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int d = gcd(jug1Capacity, jug2Capacity);
        return jug1Capacity + jug2Capacity >= targetCapacity && (targetCapacity % d == 0);
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int x, y, c;
    while (cin >> x >> y >> c)
    {
        cout << AC.canMeasureWater(x, y, c) << endl;
    }
    return 0;
}
/*
3 5 4
2 6 5
1 2 3
*/
