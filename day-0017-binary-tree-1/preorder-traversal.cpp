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
    // void helper(TreeNode* root,vector<int> &ans)
    // {
    //     if(root==NULL)return;
    //     ans.push_back(root->val);
    //     helper(root->left,ans);
    //     helper(root->right,ans);
    // }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        // helper(root,ans);
        stack<TreeNode* > s;
        s.push(root);
        while(!s.empty())
        {
            root=s.top();
            
            ans.push_back(root->val);
            s.pop();
            if(root->right!=NULL)
                s.push(root->right);
            if(root->left!=NULL)
                s.push(root->left);
            
        }
        return ans;
    }
};