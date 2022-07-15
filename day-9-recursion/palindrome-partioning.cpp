class Solution {
public:
    bool is_palindrome(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start++]!=s[end--])
                return false;
        }
        return true;
    }
    
    void helper(string s,int ind,vector<string> &st, vector<vector<string>> &ans)
    {
        if(ind == s.length())
        {
            ans.push_back(st);
            return;
        }
        for(int i=ind;i<s.length();i++)
        {
            if(is_palindrome(s,ind,i))
            {
                st.push_back(s.substr(ind,i-ind+1));
                helper(s,i+1,st,ans);
                st.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> st;
        vector<vector<string>> ans;
        
        helper(s,0,st,ans);
        return ans;
    }
};