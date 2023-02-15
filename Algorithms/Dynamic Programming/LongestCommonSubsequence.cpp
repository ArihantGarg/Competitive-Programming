#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;

    int m=s1.size(),n=s2.size();

    int dp[m+1][n+1]={};

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    cout<<dp[m][n]<<"\n";

    string ans;

    int i=m,j=n;

    while(i>0 && j>0)
    {
        if(dp[i][j]==dp[i-1][j])
            i--;
        else if(dp[i][j]==dp[i][j-1])
            j--;
        else
        {
            i--;
            j--;
            ans.push_back(s1[i]);
        }
    }

    reverse(ans.begin(),ans.end());

    cout<<ans;


    return 0;
}