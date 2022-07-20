class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n=nums.size();
        if(nums.empty())return res;
        int i,j,left,right,sum=0;
        sort(nums.begin(),nums.end());
        // vector<vector<int>> res;
        vector<int> quad(4,0);
        for(int i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                auto needed=target-nums[j]-nums[i]*1L;// elements range from -10^9 to 10^9 could be long int so auto
//The L specifies that the number is a long type, so -1L is a long set to negative one, and 1L is a long set to positive one.
                
                left=j+1;right=n-1;
                while(left<right)
                {
                    sum=nums[left]+nums[right];
                    if(sum<needed)left++;
                    else if(sum>needed)right--;
                    else
                    {
                        quad[0]=nums[i];
                        quad[1]=nums[j];
                        quad[2]=nums[left];
                        quad[3]=nums[right];
                        res.push_back(quad);
                        while(left<right and nums[left]==quad[2])left++;
                        while(left<right and nums[right]==quad[3])right--;

                    }
                }
                while(j+1<n and nums[j+1]==nums[j])++j;
                
            }
            while(i+1<n and nums[i+1]==nums[i])++i;
        }
        return res;
    }
};