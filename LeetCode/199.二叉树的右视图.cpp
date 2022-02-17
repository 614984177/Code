#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 */

// @lc code=start
// 
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                TreeNode* t = q.front(); q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
                if (size == 0) ans.emplace_back(t->val);
            }
        }
        return ans;
    }
};
// @lc code=end

