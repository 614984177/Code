#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
/*
 * @lc app=leetcode.cn id=334 lang=cpp
 *
 * [334] 递增的三元子序列
 */

// @lc code=start
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int first = nums[0], second = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > second) return true;
            else if (nums[i] > first) second = nums[i];
            else first = nums[i];
        }
        return false;
    }
};
// @lc code=end
int main()
{
    int x = 0;
    printf("%d", x);
    for (int i = 0; i < 10; i++){
        x += 1;
    }
    printf("%d", x);
    return 0;
}
/*

*/
