#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,vector<int>>

int main()
{
    int n;
    cin>>n;

    int weight[n];

    for(int i=0;i<n;i++)
        cin>>weight[i];

    map<int,string> m;

    priority_queue<pi,vector<pi>,greater<pi>> q;

    for(int i=0;i<n;i++)
        q.push({weight[i],{i}});

    //

    while(q.size()>1)
    {
        int w=0;
        vector<int> v;

        for(auto x:q.top().second)
        {
            m[x]+='0';
            v.push_back(x);
        }

        w+=q.top().first;
        q.pop();

        for(auto x:q.top().second)
        {
            m[x]+='1';
            v.push_back(x);
        }

        w+=q.top().first;
        q.pop();

        q.push({w,v});
    }

    //

    for(int i=0;i<n;i++)
    {
        string s=m[i];
        reverse(s.begin(),s.end());
        m[i]=s;
    }

    for(int i=0;i<n;i++)
        cout<<i<<" "<<m[i]<<endl;

    return 0;
}