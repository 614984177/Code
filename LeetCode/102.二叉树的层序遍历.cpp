/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push(pair<TreeNode*, int>(root, 0));
        while (!q.empty()) {
            TreeNode* t = q.front().first;
            int level = q.front().second;
            q.pop();
            if (!t) continue;
            if (ans.size() < level + 1) ans.emplace_back(vector<int>());
            ans[level].emplace_back(t->val);
            q.push(pair<TreeNode*, int>(t->left, level+1));
            q.push(pair<TreeNode*, int>(t->right, level+1));
        }
        return ans;
    }
};
// @lc code=end

