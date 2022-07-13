// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    static bool cmp(Item a,Item b)
    {
        return ((double)a.value/a.weight)>((double)b.value/b.weight);   // comapre on the bassis of ratio
    }
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        double ans=0;
        vector<double> ratio(n,0);
        sort(arr,arr+n,cmp);
        for(int i=0;i<n and W>0;i++)
        {
            // ratio[i]=arr[i].value/arr[i].weight;
            double ratio=(double) arr[i].value/arr[i].weight;
            if(arr[i].weight<=W)    // check wheter weight of item le or eq to weight of bag 
            {
                W-=arr[i].weight;
                ans+=(ratio*arr[i].weight);
            }
            else
            {
                ans+=(ratio*W);    // added the value worth the space left in bag 
                W=0;
            }
        }
        return ans;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends