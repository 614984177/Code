/*
 * @lc app=leetcode.cn id=470 lang=cpp
 *
 * [470] 用 Rand7() 实现 Rand10()
 */

// @lc code=start
// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int a, b;
        while ((a = rand7()) > 6) ;
        while ((b = rand7()) > 5) ;
        return a % 2 == 1 ? b : (b + 5);
    }
};
// @lc code=end

