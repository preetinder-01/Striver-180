class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),i,j;
        for( j=n-2;j>=0;j--)
        {
            if(nums[j]<nums[j+1])
                break;
        }
        if(j<0)
            reverse(nums.begin(),nums.end());
        else
        {
            for( i=n-1;i>j;i--)
            {
                if(nums[i]>nums[j])
                    break;
            }
            swap(nums[i],nums[j]);
            reverse(nums.begin()+j+1,nums.end());
        }
        
        
        
    }
};