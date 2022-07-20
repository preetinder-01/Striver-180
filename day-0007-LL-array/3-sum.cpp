class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         int l,r;
    vector<vector<int>>ans;
    vector<int>vec;
    if(nums.size()<3)
        return ans;
    sort(nums.begin(),nums.end());
    for(int i=0;i<nums.size()-2;i++)
    {
        if(i==0 || ((i>0) && nums[i]!=nums[i-1]))   // either i first elem or (i>0 and ith not equal to ith -1) two adjacent not equal to avoid dupicate triplets
        {
            l=i+1;  // l= next ot i 
            r=nums.size()-1;    // r traverese from right 
            int sum=0-(nums[i]);
            while(l<r)
            {
                if(nums[l]+nums[r]==sum)
                {
                    vec.push_back(nums[i]);
                    vec.push_back(nums[l]);
                    vec.push_back(nums[r]);
                    ans.push_back(vec);

                    while(l<r && nums[l]==vec[1])   // traverse until duplicates to skip
                        l++;
                    while(l<r && nums[r]==vec[2])   //traverse to skip the duplicates of rth elem 
                        r--;
                    vec.clear();
                }
                else if(nums[l]+nums[r]<sum)
                    l++;
                else
                    r--;
            }
        }
    }
    return ans;
    }
};