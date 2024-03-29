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
    bool helper(TreeNode* l,TreeNode* r)
    {   // preorder traversal for left and reverse preorder for right
        if(l==NULL or r==NULL)
            return l==r;
        if(l->val!=r->val)
            return false;
        return helper(l->left,r->right) and helper(l->right,r->left);
    }
    
    
    bool isSymmetric(TreeNode* root) {
        return root==NULL or helper(root->left,root->right);
    }
};