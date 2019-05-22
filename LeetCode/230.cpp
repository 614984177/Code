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
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> inorder;
        Inorder(inorder, root);
        return inorder[k - 1];
    }
private:
    void Inorder(vector<int> &inorder, TreeNode* root)
    {
        if (root == nullptr) return ;
        Inorder(inorder, root->left);
        inorder.emplace_back(root->val);
        Inorder(inorder, root->right);
    }
};