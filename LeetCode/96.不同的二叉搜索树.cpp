/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        // Catalan: 1,1,2,5,14,42,132,429,1430,4862
        // Catalan(n) = C(2n, n) - C(2n, n+1)
        // Catalan(n) = Sum(Catalan(i-1)∗Catalan(n−i)), 1 <= i <= n
        // Catalan(n) = 1/(n+1)*C(2n, n) = (2n)!/((n+1)!*n!) 
        // Catalan(n+1) = 2(2n+1)/(n+2)*Catalan(n)
        long long C = 1;
        for (int i = 0; i < n; i++) {
            C = C * 2 * (2*i+1) / (i+2);
        }
        return int(C);
    }
};
// @lc code=end

