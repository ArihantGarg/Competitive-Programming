#include<bits/stdc++.h>
using namespace std;

int table[100000];

bool isSubsetSum(int a[],int n,int sum)
{
    if(sum==0)
        return 1;

    if(n<=0)
        return 0;

    if(table[sum]!=-1)
    {
        ;//Nothing
    }
    else if(a[n-1]>sum)
        table[sum]=isSubsetSum(a,n-1,sum);
    else
        table[sum]=isSubsetSum(a,n-1,sum) || isSubsetSum(a,n-1,sum-a[n-1]);

    return table[sum];
}

int main()
{
    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int sum;
    cin>>sum;

    
    for(int i=0;i<=sum;i++) 
        table[i]=-1;

    cout<<isSubsetSum(a,n,sum);

    return 0;
}