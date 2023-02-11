#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[5]={2,3,6,4,7};

    int prefix[5]={};
    prefix[0]=a[0];

    for(int i=1;i<5;i++)
    {
        prefix[i]=prefix[i-1]+a[i];
        cout<<prefix[i];
    }   
}