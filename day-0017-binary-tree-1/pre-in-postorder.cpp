vector<int> PreInPostTraversal(TreeNode* root){
    stack<pair<TreeNode* ,int>> st;
    st.push({root,1});
    vector<int> pre,post,in;
    if(root==NULL)return;


    while(!st.empty())
    {
        auto it=st.top();
        st.pop();
        //1---> pre
        //2---> in
        //3---> post 
        if(it.second==1)
        {
            pre.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->left!=NULL)
            {
                st.push({it.first->left,1});
            }
        }


        
        if(it.second==2)
        {
            in.push_back(it.first->val);
            it.second++;
            st.push(it);
            if(it.first->right!=NULL)
            {
                st.push({it.first->right,1});
            }
        }
        
        else{
            post.push_back(it.first->val);
        }
    }
}
