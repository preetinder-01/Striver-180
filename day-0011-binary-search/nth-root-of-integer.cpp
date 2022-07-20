double multiply(double number,int n)
{
    double ans=1.0;
    for(int i=0;i<n;i++)
    {
        ans=ans*number;
    }
    return ans;
}


double findNthRootOfM(int n, long long m) {
	// Write your code here.
    double start=0;
    double end=m+1;
    double eps=1e-9;
    while(end-start>eps)
    {
        double mid=(start+end)/2.0;
        double  num=multiply(mid,n);
        if(num<(double)m)
        {
            start=mid;
        }
        else
            end=mid;
    }
    return start;
}
