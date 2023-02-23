#include<bits/stdc++.h>
using namespace std;

int t=0;
int start[10000]={0};
int stop[10000]={0};
int parent[10000];
int visited[10000]={0};
vector<int> adj[10000];
vector<int> transpose[10000];
vector<int> s;

void DFS(int i)
{
    start[i]=++t;
    visited[i]=1;
    cout<<i<<" ";

    for(auto x:adj[i])
    {
        if(visited[x]==0)
        {
            parent[x]=i;
            DFS(x);
        }
    }

    stop[i]=++t;
    s.push_back(i);
}

int main()
{
    //Adjacency list

    int numVertex;
    cin>>numVertex;

    

    int numEdge;
    cin>>numEdge;

    for(int i=0;i<numEdge;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        transpose[b].push_back(a);
    }

    for(int i=0;i<numVertex;i++)
        parent[i]=-1;

    //DFS

    int startvertex;
    cin>>startvertex;

    for(int i=0;i<numVertex;i++)
        if(visited[i]==0)
            DFS(i);

    //DFS on transpose in order of finishing time

    

    return 0;
}