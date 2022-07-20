/* THREE APPROACHES
APPROACH 1: BRUTE FORCE 
            for each index get water that can be trapped and for that we need to get msx  height from index 0 to that index and 
            from that index to last index
            T.C= 0(N^2)
            S.C=O(1)

AAPROACH 2: using prefic max and suffix max arrays to stire max heights and prevent nested iteration as in prev case 
            T.C = O(N)
            S.C = (2N)
            
            
APPROACH 3: using two pointers left and right and two vars leftmax height and rightmax height 
            fro each index compare left and right height then compare corresponding conditions             
            T.C = O(N)
            S.C = (1)
            
            
*/




class Solution {
public:
    int trap(vector<int>& height) {
        int l=0,r=height.size()-1,res=0,leftmax=0,rightmax=0;
        while(l<r)
        {
            if(height[l]<=height[r])
            {
                if(height[l]>=leftmax)
                    leftmax=height[l];
                else
                    res+=leftmax-height[l];
                
                l++;
            }
            else
            {
                if(height[r]>=rightmax)
                    rightmax=height[r];
                else
                    res+=rightmax-height[r];
                r--;
            }
        }
        return res;
    }
};