#include<bits/stdc++.h>
using namespace std;

int main()
{
    int sum,numCoin;
    cin>>sum>>numCoin;

    int a[numCoin];

    for(int i=0;i<numCoin;i++)
        cin>>a[i];

    int dp[sum+1];

    for(int i=0;i<=sum;i++)
        dp[i]=1e9;

    dp[0]=0;

    for(int i=0;i<sum;i++)
    {
        if(dp[i]!=1e9)
        {
            for(int j=0;j<numCoin;j++)
            {
                if(i+a[j]<=sum)
                {
                    dp[i+a[j]]=min(dp[i+a[j]],dp[i]+1);
                }
            }
        }
    }

    cout<<"\nMinimum number of coins needed : "<<dp[sum];
}