// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
     void helper(int i,int sum,vector<int> &arr,int size,vector<int> &res)
     {
         if(i==size)
         {
             res.push_back(sum);
             return;
         }
         helper(i+1,sum+arr[i],arr,size,res);
         helper(i+1,sum,arr,size,res);
     }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> res;
        helper(0,0,arr,N,res);
        sort(res.begin(),res.end());
        return res;
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends