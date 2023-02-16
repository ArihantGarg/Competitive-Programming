#include<bits/stdc++.h>
using namespace std;


int table[1000][1000];


bool checkPalindrome(string s,int start,int end)
{
    while(start<end)
    {
        if(s[start]!=s[end])
            return 0;

        start++;
        end--;
    }

    return 1;
}


int MinPalindromePartition(string s,int start,int end)
{
    if(start>=end || checkPalindrome(s,start,end))
        return 0;

    if(table[start][end]!=-1)
        return table[start][end];

    int ans=end-start,count=0;

    for(int i=start;i<end;i++)
    {
        count=MinPalindromePartition(s,start,i)+MinPalindromePartition(s,i+1,end)+1;

        ans=min(ans,count);
    }

    table[start][end]=ans;

    return ans;
}


int main()
{
    string s;
    cin>>s;

    int n=s.size();

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            table[i][j]=-1;

    cout<<"Minimum number of partitions needed is : "<<MinPalindromePartition(s,0,n-1);

    return 0;
}