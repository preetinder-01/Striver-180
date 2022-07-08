class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>v(150,0);    // to store char and its index 
        int maxLen=0;
        int n=s.length();
        int i=0,j=0;
        while(j<n)
        {
            if(v[s[j]]==0)
            {
                maxLen=max(maxLen,(j-i+1));
                    v[s[j]]=1;
                j++;
                
            }
            else
            {
                i++;
                j=i;
                fill(v.begin(),v.end(),0);
            }
            
        }
        return maxLen;
    }
};