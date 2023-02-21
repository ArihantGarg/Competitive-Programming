#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int main()
{
    // Input - Assuming Weighted undirected graph
    int numVertex;
    cin>>numVertex;

    vector<pi> adj[numVertex];

    int numEdge;
    cin>>numEdge;

    for(int i=0;i<numEdge;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;

        adj[a].push_back({b,weight});
        adj[b].push_back({a,weight});
    }

    // Prim's Algorithm

    priority_queue<pi,vector<pi>,greater<pi>> q;
    int parent[numVertex],visited[numVertex],key[numVertex];

    for(int i=0;i<numVertex;i++)
    {
        key[i]=1e9;
        visited[i]=0;
    }

    q.push({0,0});
    key[0]=0;

    while(!q.empty())
    {
        pi u=q.top();
        q.pop();

        if(visited[u.second]==1)
            continue;
        visited[u.second]=1;

        for(auto v:adj[u.second])
        {
            if(visited[v.first]==0 && v.second < key[v.first])
            {
                key[v.first]=v.second;
                parent[v.first]=u.second;
                q.push({v.second,v.first});
            }
        }
    }

    for(int i=1;i<numVertex;i++)
    {
        cout<<i<<" "<<parent[i]<<"\n";
    }

    return 0;
}