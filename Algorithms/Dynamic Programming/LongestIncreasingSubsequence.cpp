#include<bits/stdc++.h>
using namespace std;

int main()
{
    // O(n^2) solution

    int n;
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    int longest[n]={0};

    int ans=1;

    for(int i=0;i<n;i++)
    {
        int temp=0;

        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
                temp=max(temp,longest[j]);
        }

        longest[i]=temp+1;
        ans=max(longest[i],ans);
    }

    cout<<ans;

    return 0;
}