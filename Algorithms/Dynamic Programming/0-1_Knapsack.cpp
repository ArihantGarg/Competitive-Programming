#include<bits/stdc++.h>
using namespace std;


int dp[100000];


int MaxKnapsack(int volume,int n,int vol[],int cost[])
{
    if(volume==0 || n==0)
        return 0;

    if(dp[volume]!=-1)
    {
        ;//Nothing
    }
    else if(vol[n-1]>volume)
        dp[volume]=MaxKnapsack(volume,n-1,vol,cost);
    else
        dp[volume]=max(MaxKnapsack(volume,n-1,vol,cost),cost[n-1]+MaxKnapsack(volume-vol[n-1],n-1,vol,cost));

    return dp[volume];
}


int main()
{
    int volume;
    cin>>volume;

    int n;
    cin>>n;

    int vol[n],cost[n];

    for(int i=0;i<n;i++)
        cin>>vol[i];

    for(int i=0;i<n;i++)
        cin>>cost[i];

    for(int i=0;i<=volume;i++)
            dp[i]=-1;

    cout<<MaxKnapsack(volume,n,vol,cost);


    return 0;
}