class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     int n1=nums1.size();
        vector<int> ans(n1);        .. to store the answers of nums1 
        unordered_map<int,int> m;   // using map to store nge of array2 
        stack<int> st;
        
        for(int i=nums2.size()-1;i>=0;i--)
        {
            if(!st.empty() and st.top()<=nums2[i])
                st.pop();
            
            if(st.empty())
                m[nums2[i]]=-1;
            else
                m[nums2[i]]=st.top();
            st.push(nums2[1]);
        }
        
        for(int i=0;i<n1;i++)
        {
            ans[i]=m[nums1[i]];
        }
        return ans;
        
    }
};