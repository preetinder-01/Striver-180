int countsmallerThanMid(vector<int> &row,int mid)
{
    int lo=0,h=row.size()-1;
    while(lo<=h)
    {int md=(lo+h)>>1;
    if(row[md]<=mid)
        lo=md+1;
    else
    h=md-1;}
    return lo;
}


int Solution::findMedian(vector<vector<int> > &A) {
    int n=A.size();
    int m=A[0].size();
    int start=0;
    int end=1e9;
    while(start<=end)
    {
        int mid=(start+end)>>1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=countsmallerThanMid(A[i],mid);
        }
        if(cnt<=(n*m)/2)start=mid+1;
        else
        end=mid-1;
    }
    return start;
}
