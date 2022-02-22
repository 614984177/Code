#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
 */

// @lc code=start

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int ans;
    int sumNumbers(TreeNode* root) {
        ans = 0;
        dfs(root, 0);
        return ans;
    }

    void dfs(TreeNode* x, int num) {
        num = num * 10 + x->val;
        if (x->left == nullptr && x->right == nullptr) {
            ans += num;
            return ;
        }
        if (x->left) dfs(x->left, num);
        if (x->right) dfs(x->right, num);
    }
};
// @lc code=end

