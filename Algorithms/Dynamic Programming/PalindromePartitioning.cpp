#include<bits/stdc++.h>
using namespace std;


int MinPalindromePartition(string s)
{
    int n=s.size();
    int table[n][n];
    int partition[n];

    for(int i=0;i<n;i++)
        table[i][i]=1;

    for(int size=2;size<=n;size++)
    {
        for(int i=0;i<=n-size;i++)
        {
            int j=i+size-1;

            if(s[i]==s[j] && size==2)
            {
                table[i][j]=1;
            }
            else if(s[i]==s[j] && table[i+1][j-1]==1)
            {
                table[i][j]=1;
            }
            else
                table[i][j]=0;
        }
    }


    for(int i=0;i<n;i++)
    {
        if(table[0][i]==1)
            partition[i]=0;
        else
        {
            partition[i]=1e9;
            for(int j=0;j<i;j++)
            {
                if(table[j+1][i]==1)
                    partition[i]=min(partition[i],1+partition[j]);
            }
        }
    }

    return partition[n-1];
}


int main()
{
    string s;
    cin>>s;

    cout<<"Minimum number of partitions needed is : "<<MinPalindromePartition(s);

    return 0;
}