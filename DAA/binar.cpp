#include<iostream>
using namespace std;
int bin_srch_rec(int p[],int beg,int lst,int x)
{
    if(beg>lst)
        return -1;
    int mid = (beg + lst)/2;
    if(p[mid]==x)
        return mid;
    if(x>p[mid])
        return bin_srch_rec(p,mid+1,lst,x);
    if(x<p[mid])
        return bin_srch_rec(p,beg,mid-1,x);
}

int main()
{
    int n,i,x;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cin>>x;
    i = bin_srch_rec(arr,0,n-1,x);
    cout<<i;
    cout<<endl;
    return 0;
}