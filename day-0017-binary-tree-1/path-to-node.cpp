/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 bool helper(TreeNode* root,vector<int>& ds,int target)
 {
     if(root==NULL)
     return false;
     ds.push_back(root->val);
     if(root->val==target)
     {
         return true;
     }
     if(helper(root->left,ds,target) or helper(root->right,ds,target))  // if found then return true wihtout popping 
     return true;
     ds.pop_back(); // else pop and return false 
     return false;
     
     
 }
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int>ds;
    if(A==NULL)
    return ds;
    helper(A,ds,B);
    return ds;
}
