bool isPossible(vector<int> A,int B,int barrier)
{
    int allocated_st=1,pages=0;
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>barrier)return false;
        if(pages+A[i]>barrier)
        {
            allocated_st++;
            pages=0;
            pages+=A[i];
        }
        else{
            pages+=A[i];
        }
    }
    if(allocated_st>B)
    return false;
    return true;
}


int Solution::books(vector<int> &A, int B) {
    int mn=INT_MAX;
    int sum=0;
    int res=-1;
    if(A.size()<B)return -1;
    for(auto it:A)
    {
        mn=min(mn,it);
        sum+=it;
        
    }
    int low=mn,high=sum;
    while(low<=high)
    {
        int mid=(low+high)>>1;
        if(isPossible(A,B,mid))
        {
             res=mid;
             high=mid-1;
        }
        else
        low=mid+1;
    }
    return res;
}

