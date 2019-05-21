/**
 * Definition for a binary tree node.
 * struct TreeNode 
 * {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution 
{
public:
    const int INF = 0x3f3f3f3f;
    int MAX;
    int dfs(TreeNode* root)
    {
        if (root == nullptr) return ;
        int l = 0, r = 0;
        if (root->left != nullptr) l = max(l, dfs(root->left));
        if (root->right != nullptr) r = max(r, dfs(root->right));
        MAX = max(MAX, l + r + root->val);
        return max(l, r) + root->val;
    }
    int maxPathSum(TreeNode* root) 
    {
        MAX = -INF;
        dfs(root);
        return MAX;
    }
};