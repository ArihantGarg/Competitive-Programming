#include<bits/stdc++.h>
using namespace std;

// O(n^2) DP solution

int main()
{
    string s1,s2;
    cout<<"Enter string 1 : ";
    cin>>s1;
    cout<<"Enter string 2 : ";
    cin>>s2;

    int m=s1.size(),n=s2.size();
    int dp[m+1][n+1];

    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1];
            else
                dp[i][j]=min(1+dp[i-1][j],min(1+dp[i][j-1],2+dp[i-1][j-1]));
        }
    }

    cout<<"Minimum edit distance is : "<<dp[m][n];

    return 0;
}