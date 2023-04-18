#include<bits/stdc++.h>
using namespace std;

// O(n^3) DP solution

void solve(int* check,int n,int x,int y)
{
    if(x!=y)
    {
        int m=*(check+x*(n+1)+y);

        cout<<"(";
        solve(check,n,x,m);
        solve(check,n,m+1,y);
        cout<<")";
    }
    else
        cout<<(char)(65+x);
}

int main()
{
    int n;
    cout<<"Enter number of matrices : ";
    cin>>n;

    vector<pair<int,int>> a;
    cout<<"Enter elements : ";
    int x;
    cin>>x;
    a.push_back({x,0});

    for(int i=1;i<n;i++)
    {
        int x;
        cin>>x;
        a[i-1].second=x;
        a.push_back({x,0});
    }

    cin>>x;
    a[n-1].second=x;

    int dp[n+1][n+1];
    int check[n+1][n+1];

    for(int size=0;size<n;size++)
    {
        for(int j=0;j<n-size;j++)
        {
            int row=j;
            int col=size+j;

            if(row==col)
                dp[row][col]=0;
            else
            {
                dp[row][col]=1e9;
                for(int k=row;k<col;k++)
                {
                    if( dp[row][col] > dp[row][k]+dp[k+1][col]+a[row].first*a[k].second*a[col].second)
                    {
                        dp[row][col]=dp[row][k]+dp[k+1][col]+a[row].first*a[k].second*a[col].second;
                        check[row][col]=k;
                    }
                }
            }
        }
    }

    cout<<"Minimum cost of matrix multiplication is : "<<dp[0][n-1];
    cout<<"\nOrder of Multiplication is : ";
    solve((int*) check,n,0,n-1);

    return 0;
}