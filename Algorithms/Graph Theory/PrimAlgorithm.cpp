#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>

int main()
{
    // Input - Assuming Weighted directed graph
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

    priority_queue< pi,vector<pi>,greater<pi> > pq; //Minimum Binary Heap

    int startvertex=0;//We can take any start vertex

    int dist[numVertex],parent[numVertex];

    for(int i=0;i<numVertex;i++)
    {
        dist[i]=1e9;
        parent[i]=NULL;
    }

    dist[0]=0;

    pq.push({dist[0],0});

    while(!pq.empty())
    {
        int u=pq.top().second;
        int distance=pq.top().first;

        pq.pop();

        if(dist[u]==distance)
        {
            for(auto x:adj[u])
            {
                if(dist[x.first]>dist[u]+x.second)
                {
                    dist[x.first]=dist[u]+x.second;
                    parent[x.first]=u;

                    pq.push({dist[x.first],x.first});
                }
            }
        }
    }

    //Printing MST

    cout<<"\nMST Edges\n";

    for(int i=1;i<numVertex;i++)
    {
        cout<<parent[i]<<" - "<<i<<"\n";
    }

    return 0;
}