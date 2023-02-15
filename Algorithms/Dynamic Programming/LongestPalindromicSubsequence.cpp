#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin>>s;

    int n=s.size();

    int dp[n][n]={};

    for(int i=0;i<n;i++)
        dp[i][i]=1;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            int row=j;
            int col=i+j+1;

            if(s[row]==s[col])
                dp[row][col]=2+dp[row+1][col-1];
            else
                dp[row][col]=max(dp[row+1][col],dp[row][col-1]);
        }
    }

    cout<<dp[0][n-1];

    return 0;
}