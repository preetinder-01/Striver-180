class Solution {
public:
    
    void helper(int ind,vector<int> candidates,int target,vector<int> &ds,vector<vector<int>> &res)
    {
        
            if(target==0)
            { 
                res.push_back(ds);
                return;
            }
            for(int i=ind;i<candidates.size();i++)
            {
                if(i>ind and candidates[i]==candidates[i-1])continue;
                if(candidates[i]>target)break;
                ds.push_back(candidates[i]);
                helper(i+1,candidates,target-candidates[i],ds,res);
                ds.pop_back();    
            }
            
        // helper(ind+1,candidates,target,ds,res);
    }
    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        helper(0,candidates,target,ds,res);
        return res;
    }
};





/*

Basically to bypass that set usage to discard the duplicate vectors in 2d vector we used conecpt of subsequence that now for choosing elem for certain position instead of doing pick or not for a position with each elem 
Now for a opsition we used for loop to pick elements from array , to skip duplicates we added conditions

*/