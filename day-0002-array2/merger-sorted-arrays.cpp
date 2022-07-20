/*
We can take advantage of ascending sorted arrays. 
Intuition - 
         We will fill our final answer array from last by taking two pointers i and j which will be pointing first arrays last index and second arrays last index respectively. We will compare the elements at ith and jth index elements of array 1 and array 2 respectively. In comparing whichever will be the greater among them we will put that element at our answer arrays last index and we will decrement the grater element index and answer array index. Likewise we will fill our answer array 
Implementation - 
*/

 void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(i>=0 && j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else
            {
                nums1[k--]=nums2[j--];
            }
        }
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
    }
    /*
//Time Complexity - O(m+n)
//Space Complexity - O(1)
Note - Here we are storing our answer array in given arr1
*/



/* 

APPROACH TRIED :
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int gap=ceil((m+n)/2);
        int k=m;int l=0;
        while(k<m+n)
        {
            nums1[k++]=nums2[l++];
        }
        // cout<<nums1;
        int i=0,j;
        while(gap>0)
        {
            i=0;j=gap;
            while(j<=m+n)
            {
                if(nums1[i]>=nums1[j])
                {
                    swap(nums1[i],nums1[j]);
                    i++;
                    j++;
                    
                }
                else
                {
                    i++;
                    j++;
                }
            }
            gap=ceil(gap/2);
        }
    }
};

  */





