class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // unordered_map<int,int>m;
        // int count=0;
        // m[nums[0]]++;
        // for(int i=1;i<nums.size();i++)
        // {
        //     m[nums[i]]++;
        //     if(m[nums[i]-1]==1 or m[nums[i]+1]==1)
        //         count+=2;;
        // }
        // return count;
        
        unordered_set<int> s(nums.begin(),nums.end());
        int seq=0;
        for(int i=0;i<nums.size();i++)
        {
            if(s.find(nums[i]-1)!=s.end())  // prev elem present hence thsi is not start
                continue;
            else
            {
                int count=0;
                int elem=nums[i];
                while(s.find(elem)!=s.end())
                {
                    count++;
                    elem++;
                }
                seq=max(seq,count);
            }
        }
        return seq;
    }
};