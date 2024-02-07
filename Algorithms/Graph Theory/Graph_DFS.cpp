#include<bits/stdc++.h>
using namespace std;

int numVertex,numEdge;
int tim,d[10000],f[10000],parent[10000],visited[10000];
vector<int> adj[10000];

void dfs_visit(int currVertex)
{
    visited[currVertex]=1;
    d[currVertex]=++tim;

    cout<<currVertex<<" ";

    for(auto x:adj[currVertex])
    {
        if(visited[x]==0)
        {
            parent[x]=currVertex;
            dfs_visit(x);
        }
    }

    f[currVertex]=++tim;
}

void dfs(int startVertex)
{
    for(int i=0;i<numVertex;i++)
    {
        visited[i]=0;
        parent[i]=-1;
    }

    tim=0;

    dfs_visit(startVertex);

    for(int i=0;i<numVertex;i++)
    {
        if(visited[i]==0)
            dfs_visit(i);
    }
}

int main()
{
    cout<<"Enter number of vertices : ";
    cin>>numVertex;

    cout<<"Enter number of edges : ";
    cin>>numEdge;

    cout<<"Enter all edges :\n";

    for(int i=0;i<numEdge;i++)
    {
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u); //If directed, remove this
    }

    int startVertex;
    cout<<"Enter starting vertex : ";
    cin>>startVertex;

    dfs(startVertex);

    return 0;
}