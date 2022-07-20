// this was based on observation of indexes of 1st and 2nd instance on left and right of single element

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0;
        int high=n-2;
        while(low<=high)
        {
            int mid=(low+high)>>1;;
            if(nums[mid]==nums[mid^1])
            {
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return nums[low];      
    }
};

// to check for left hlf 
//odd index -->  second instance ==>> check on the left is 1st instance present or not 
//even index-->  1st instace      ==> check on right if same 