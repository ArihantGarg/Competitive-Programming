#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    int m=s1.size(),n=s2.size();

    int dp[2][n+1]={};

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i%2][j]=1+dp[(i-1)%2][j-1];
            else
                dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
        }
    }

    cout<<dp[m%2][n]<<"\n";

    return 0;
}