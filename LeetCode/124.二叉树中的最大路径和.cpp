#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
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
    int dfs(TreeNode* root) {
        int l = 0, r = 0;
        if (root->left) {
            l = max(l, dfs(root->left));
        }
        if (root->right) {
            r = max(r, dfs(root->right));
        }
        ans = max(ans, root->val + l + r);
        return root->val + max(l, r);
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        if (root) dfs(root);
        return ans;
    }
};
// @lc code=end

