#include <bits/stdc++.h> 

long long merge(long long *arr,long long s, long long m,long long e)
{
    long long n1=m-s+1;
    long long n2=e-m;
        
        long long a[n1];
    long long b[n2];
    for(long long i=0;i<n1;i++)
    {
        a[i]=arr[s+i];
    }
    for(long long j=0;j<n2;j++)
    {
        b[j]=arr[j+1+m];
    }
    long long res=0;
    long long i=0,j=0,k=s;
    while(i<n1 and j<n2)
    {
        if(a[i]<b[j])
        {
            arr[k++]=a[i++];
        }
        else
        {
            arr[k++]=b[j++];
            res+=(n1-i);
        }
    }
    while(i<n1)
    {
        arr[k++]=a[i++];
    }
    while(j<n2)
    {
        arr[k++]=b[j++];
    }
    return res;
}

long long count(long long *arr,int p,int r)
{
    long long res=0;
    if(p<r)
    {
        long long  q=(p+r)/2;
        res+=count(arr,p,q);
        res+=count(arr,q+1,r);
        res+=merge(arr,p,q,r);
        
    }
    return res;
}

long long getInversions(long long *arr, int n){
    // Write your code here.
    return count(arr,0,n-1);
    
}