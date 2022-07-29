class Solution {
public:
    bool isValid(string s) {
        int n=s.length();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty() or (s[i]=='{' or s[i]=='[' or s[i]=='('))
               {
                   st.push(s[i]);
               }
               else
               {
                   if( (st.top()=='(' and s[i]==')') or(st.top()=='[' and s[i]==']') or (st.top()=='{' and s[i]=='}'))
                       st.pop();
                   else
                       return 0;
               }
        }
        if(st.empty())
               return 1;
        return 0;
    }
};