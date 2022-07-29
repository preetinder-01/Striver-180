class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() and dq.front()==i-k) dq.pop_front();   // to remove out of bound 
            while(!dq.empty() and nums[dq.back()]<nums[i])  // new elem is greater then pop all from back till not empty and elem still greater 
                dq.pop_back();
            dq.push_back(i);    // add new elem to dq 
            if(i>=k-1)ans.push_back(nums[dq.front()]);   
        }
        return ans;
    }
};