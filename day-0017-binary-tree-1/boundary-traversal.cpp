/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
     void addleft(TreeNode* root,vector<int>& res)
     {
         Node* curr=root->left;
         while(curr)
         {
             if(!isLeaf(curr))res.push_back(curr->val);
             if(!curr->left)
                curr=curr->left;
             else
             curr=curr->right;

         }
     }
     void addright(TreeNode* root,vector<int>& res)
     {
         vector<int>temp;
         TreeNode* curr=root->right;
         while(curr)
         {
             if(!isLeaf(curr))temp.push_back(Curr->val);
             if(!root->right)curr=curr->right;
             else
             curr=curr->left;

         }
         for(int i=0;i<temp.size();i++)
         {
             res.push_back(temp[i]);
         }
     }

     void addleaves(TreeNode* root,vector<int>& res)
     {
         if(isLeaf(root))
         {
             res.push_back(root->val);
             return;
         }
         if(root->left)addleaves(root->left,res);
         if(root->right)addleaves(root->right,res);
     }


    vector<int> boundaryOfBinaryTree(TreeNode *root) {
        // write your code here
        vector<int> res;
        if(!root)return res;
        if(!isLeaf(root))res.push_back(root->val);
        addleft(root,res);
        addleaves(root,res);
        addright(root,res);
        return res;

    }
};