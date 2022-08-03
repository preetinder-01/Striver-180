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
    int  height(TreeNode* root,int& diameter)
    {
        if(root==NULL)
            return 0;
        int l=height(root->left,diameter);
        int r=height(root->right,diameter);
        diameter=max(diameter,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // naive approach : at each node calculate lh+rh and retur max of all nodes 
        // TC: O(N^2)
         
        //optimal : modify height function add variable for diamter and calculate using l+r
        int diameter=0;
        height(root,diameter);
        return diameter;
    }
};