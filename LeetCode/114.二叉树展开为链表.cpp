#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        stack<TreeNode*> st;
        if (root) {
            st.emplace(root);
        }
        TreeNode* prev = nullptr;
        while (!st.empty()) {
            TreeNode* cur = st.top(); st.pop();
            if (prev) {
                prev->left = nullptr;
                prev->right = cur;
            }
            if (cur->right) {
                st.emplace(cur->right);
            }
            if (cur->left) {
                st.emplace(cur->left);
            }
            prev = cur;
        }
    }
};
// @lc code=end

