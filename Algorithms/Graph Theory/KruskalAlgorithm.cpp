#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

void makeset(vector<pi> &a,int x)
{
    a[x].first=x;
    a[x].second=0;
}

int find(vector<pi> &a,int x)
{
    while(x!=a[x].first)
        x=a[x].first;
    return x;
}

void unionset(vector<pi> &a,int x,int y)
{
    int r=find(a,x);
    int s=find(a,y);

    if(r==s)
        return;
    else if(a[r].second>a[s].second)
        a[s].first=r;
    else
        a[r].first=s;

    if(a[r].second==a[s].second)
        a[s].second++;
}

int main()
{
    int numVertex;
    cin>>numVertex;

    vector<pair<int,pi>> edge;

    int numEdge;
    cin>>numEdge;

    for(int i=0;i<numEdge;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;

        edge.push_back({weight,{a,b}});
    }

    //Kruskal

    sort(edge.begin(),edge.end());

    vector<pi> a(numVertex);
    for(int i=0;i<numVertex;i++)
        makeset(a,i);

    int count=0,i=0;

    vector<pi> ans;

    while(count<numVertex-1 && i<numEdge)
    {
        int u=edge[i].second.first;
        int v=edge[i].second.second;

        if(find(a,u)!=find(a,v))
        {
            unionset(a,u,v);
            ans.push_back({u,v});
            count++;
        }

        i++;
    }

    for(auto x:ans)
    {
        cout<<x.first<<" "<<x.second<<"\n";
    }

    return 0;
}