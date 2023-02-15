#include<bits/stdc++.h>
using namespace std;

int table[100][10000];

bool isSubsetSum(int a[],int n,int sum)
{
    if(sum==0)
        return 1;

    if(n<=0)
        return 0;

    if(table[n][sum]!=-1)
    {
        ;//Nothing
    }
    else if(a[n-1]>sum)
        table[n][sum]=isSubsetSum(a,n-1,sum);
    else
        table[n][sum]=isSubsetSum(a,n-1,sum) || isSubsetSum(a,n-1,sum-a[n-1]);

    return table[n][sum];
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

    for(int i=1;i<=n;i++)
        for(int j=0;j<=sum;j++) 
            table[i][j]=-1;

    cout<<isSubsetSum(a,n,sum);

    return 0;
}