/*
make a vector of start and end 
sort based on end time 
traverse and check for condition 
*/


// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    static bool cmp(vector<int> &a,vector<int> &b)
    {
        return a[1]<b[1];
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        int count=1;
        int k=0;
        vector<vector<int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({start[i],end[i]});
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=1;i<n;i++)
        {
            if(v[i][0]>v[k][1])
            {
                count++;
                k=i;
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends