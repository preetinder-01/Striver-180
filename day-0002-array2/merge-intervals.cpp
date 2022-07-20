class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // vector<int> p;
        vector<vector<int>> ans;
        if(intervals.size()==0)return ans;
        vector<int> p=intervals[0];
        for(auto it:intervals)
        {
            if(it[0]<=p[1])
            {
                p[1]=max(p[1],it[1]);
            }
            else
            {
                ans.push_back(p);
                p=it;
            }
        }
        ans.push_back(p);
        return ans;
    }
};