#include<bits/stdc++.h>
using namespace std;

int  countpath(int i,int j,int m,int n)
{
    if((i==m-1)and (j==n-1))return 1;
    if(i>=m or j>=n)return 0;
    else return countpath(i+1,j,m,n)+countpath(i,j+1,m,n);
}


int count(int i,int j,int m,int n)
{
        return countpath(i,j,m,n);
}




int main()
{
    int m,n;
    cin>>m>>n;
    // cout<<m<<n<<endl;
    cout<<count(0,0,m,n);
    return 0;
}