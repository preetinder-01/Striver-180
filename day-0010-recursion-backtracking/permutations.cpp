class Solution {
public:
    /*
    
    vector<vector<int>> ans;
    void solve(vector<int> &nums,int index)
    {
        //base cae
        if(index==nums.size())
        {ans.push_back(nums);return;}
        for(int i=index;i<nums.size();i++)
        {
            swap(nums[i],nums[index]);  // swapping with elements to the right 
            solve(nums,index+1);
            swap(nums[i],nums[index]);  // swapping back to turn it back to original 
        }
        return ;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums,0);
        return ans;
    }
    
    
    */
    
    
    void helper(vector<int> &nums,int m[],vector<vector<int>> &res,vector<int> &ds)
    {
        if(ds.size()==nums.size())
        {
            res.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            if(!m[i])
            {
                ds.push_back(nums[i]);
                m[i]=1;
                helper(nums,m,res,ds);
                m[i]=0;
                ds.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        int m[nums.size()];
        vector<vector<int>> res;
        vector<int> ds;
        for(int i=0;i<nums.size();i++)
        m[i]=0;
        helper(nums,m,res,ds);    
        
        
        return res;
    }
};