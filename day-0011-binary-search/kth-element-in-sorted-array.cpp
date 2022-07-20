//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int nums1[], int nums2[], int n, int m, int k)
    {
        // binary search always on smaller part
        if(n>m)return kthElement(nums2,nums1,m,n,k);
        // edge case1: k< # elements of first array    then high=k here minimum is 0 but maximum we can take is k as # > k
        // edge case2: #elem of second  array <k        then min_low=k-(#secondarray) and high =n    i.e. minimum element to take is 1 adn max we can take all as # is less than k 
        
        
        int low=max(0,k-n),high=min(k,m);
        while(low<=high)
        {
            int cut1=(low+high)>>1;
            int cut2=k-cut1;;
            int l1=cut1==0?INT_MIN:nums1[cut1-1];
            int l2=cut2==0?INT_MIN:nums2[cut2-1];
            int r1=cut1==m?INT_MAX:nums1[cut1];
            int r2=cut2==n?INT_MAX:nums2[cut2];
            if(l1<=r2 and l2<=r1)
            {
                
                    return max(l1,l2);
                
            }
            else if(l1>r2)
                high=cut1-1;    // for left shift of cut 1
            else
                low=cut1+1;     // for right shift of cut 1
        
        
        }
        return 1;
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends