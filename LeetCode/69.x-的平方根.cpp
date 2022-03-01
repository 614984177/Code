#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        double C = x, x0 = C;
        // f(x) = x^2 - C, 取(x0, x0^2 - C)点，此处切线斜率即f(x)‘ = 2x0，(y - (x0^2-C)) = 2x0(x - x0)， y = 2x0(x - x0) + (x0^2-C)
        // 与x轴交点为: 0 = 2x0(x - x0) + (x0^2-C), x = (x0^2 + C) / (2*x0)
        while (x0) {
            double x1 = (x0*x0+C) / (2*x0);
            if (x0 - x1 < 1e-7) break;
            x0 = x1;
        }
        return int(x0);
    }
};
// @lc code=end

int main()
{
    Solution AC;
    int n;
    while (cin >> n) {
        cout << AC.mySqrt(n) << endl;
    }
    return 0;
}
/*
4
8
1
*/