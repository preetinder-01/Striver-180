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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        
        // left height
        int lh=0;
        if(root->left)
        {
            lh=height(root->left);
            if(lh==-1)
                return -1;
        }
        // for right 
        int rh=0;
        if(root->right)
        {
            rh=height(root->right);
            if(rh==-1)
                return -1;
        }
        
        if(abs(lh-rh)<=1)
            return 1+max(lh,rh);
        return -1;
        
    }
    bool isBalanced(TreeNode* root) {
        
        // we modified the height functikon to check for balanced and return height if balanced else return -1
        if(height(root)==-1)
            return 0;
        return 1;
        
    }
};