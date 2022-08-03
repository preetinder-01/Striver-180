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
//     void helper(TreeNode* root,vector<int> &ans)
//     {
//         if(root==NULL)return;
        
//         helper(root->left,ans);
//         helper(root->right,ans);
//         ans.push_back(root->val);
//     }
    vector<int> postorderTraversal(TreeNode* root) {
     // vector<int> ans;
     // helper(root,ans);
        
        /*
        USING 2 STACKS 
        
        vector<int>ans;
        stack<TreeNode* >s1;
        stack<TreeNode* >s2;
        if(root==NULL)return ans;
        s1.push(root);
        while(!s1.empty())
        {
            root=s1.top();
            s1.pop();
            s2.push(root);
            
            if(root->left!=NULL)
            {
                s1.push(root->left);
                
            }
            if(root->right!=NULL)
            {
                s1.push(root->right);
            }
            
        }
        while(!s2.empty())
        {
            ans.push_back(s2.top()->val);
            s2.pop();
        }
        
        
        return ans;   
        
        */
        
        
        
        
        // using 1 stack only 
        stack<TreeNode* >s;
        vector<int>ans;
        TreeNode* temp;
        TreeNode* curr=root;
        while(curr!=NULL or !s.empty()) 
        {
            if(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            else
            {
                temp=s.top()->right;
                if(temp==NULL)
                {
                    temp=s.top();
                    s.pop();
                    ans.push_back(temp->val);
                    while(!s.empty() and temp==s.top()->right)
                    {
                        temp=s.top();
                        s.pop();
                        ans.push_back(temp->val);
                    }
                }
                else
                {
                    curr =temp;
                }
            }
            
        }
        return ans;
    }
};