#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    int c[n];

    for(int i=0;i<n;i++)
        cin>>c[i];

    int dp[n+1];

    for(int i=0;i<=n;i++)
        dp[i]=-1;

    dp[0]=0;

    for(int i=0;i<n;i++)
    {
        if(dp[i]==-1)
            continue;
        else
        {
            for(int j=0;j<n;j++)
            {
                if(i+j+1<=n)
                    dp[i+j+1]=max(dp[i+j+1],dp[i]+c[j]);
            }
        }
    }

    cout<<dp[n];


    return 0;
}