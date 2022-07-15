class Solution {
public:
    void helper(int ind,vector<int> &candidates,vector<int> &ds,vector<vector<int>> &res,int target)
    {
        
        
        if(ind==candidates.size())
        {
            if(target==0)
            res.push_back(ds);
            return;
        }
        if(candidates[ind]<=target){
        ds.push_back(candidates[ind]);
        // sum+=candidates[ind];
        helper(ind,candidates,ds,res,target-candidates[ind]);
        ds.pop_back();}
        helper(ind+1,candidates,ds,res,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ds;
        helper(0,candidates,ds,res,target);
        return res;
        
    }
};