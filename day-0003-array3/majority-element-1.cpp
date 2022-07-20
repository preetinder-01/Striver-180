class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int comparator=0;
        int count=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[comparator])count++;
            else
            {
                count--;
                if(count<0)
                {
                comparator=i;
                count=1;
                }
            }
            
        }
        return nums[comparator];
    }
};