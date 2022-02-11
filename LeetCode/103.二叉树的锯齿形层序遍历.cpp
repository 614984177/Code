/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        bool flag = true;
        while (!q.empty()) {
            int levelSize = q.size();
            ans.emplace_back(vector<int>());
            while (levelSize--) {
                TreeNode* t = q.front(); q.pop();
                ans.back().emplace_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            flag = !flag;
            if (flag) reverse(ans.back().begin(), ans.back().end());
        }
        return ans;
    }
};
// @lc code=end

