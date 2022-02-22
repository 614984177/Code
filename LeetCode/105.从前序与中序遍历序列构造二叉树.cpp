#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    unordered_map<int, int> mp;
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int pre_l, int pre_r, int in_l, int in_r) {
        if (pre_l >= pre_r) return nullptr;
        TreeNode* root = new TreeNode(preorder[pre_l]);
        int pos = mp[preorder[pre_l]], len = pos - in_l;
        root->left = build(preorder, inorder, pre_l + 1, pre_l + len + 1, in_l, pos);
        root->right = build(preorder, inorder, pre_l + len + 1, pre_r, pos + 1, in_r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return build(preorder, inorder, 0, preorder.size(), 0, inorder.size());
    }
};
// @lc code=end

