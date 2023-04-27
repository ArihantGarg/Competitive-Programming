#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10000];
int visited[10000],edge[10000];

bool dfs(int v)
{
    if(visited[v])
        return 0;

    visited[v]=1;

    for(int x:adj[v])
    {
        if(edge[x]==-1 || dfs(edge[x]))
        {
            edge[x]=v;
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n,m;
    cout<<"Enter number of jobs : ";
    cin>>n;
    cout<<"Enter number of seekers : ";
    cin>>m;

    int numEdge;
    cout<<"Enter number of edges;";
    cin>>numEdge;


    cout<<"Enter  edges :\n";
    for(int i=0;i<numEdge;i++)
    {   
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
    }

    //

    for(int i=0;i<m;i++)
        edge[i]=-1;


    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            visited[j]=0;

        dfs(i);
    }

    //

    int ans=0;
    vector<pair<int,int>> res;
    for(int i=0;i<m;i++)
    {
        if(edge[i]!=-1)
        {
            res.push_back({edge[i],i});
            ans++;
        }
    }
    sort(res.begin(),res.end());

    cout<<"\nSize of maximum matching is : "<<ans;

    cout<<"\nMaximum matching is :\n";
    for(auto x:res)
        cout<<x.first<<" - "<<x.second<<"\n";


    return 0;
}