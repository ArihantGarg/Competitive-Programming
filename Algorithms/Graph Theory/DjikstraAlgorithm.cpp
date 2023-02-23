#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

int main()
{
    //Input graph

    int numVertex;
    cout<<"Enter number of vertices: ";
    cin>>numVertex;

    int numEdge;
    cout<<"Enter number of edges: ";
    cin>>numEdge;

    vector<pair<int,int>> adj[numVertex];

    for(int i=0;i<numEdge;i++)
    {
        cout<<"\nEnter edge vertices and weight: \n";
        int u,v,weight;
        cin>>u>>v>>weight;

        adj[u].push_back({v,weight});
    }

    int startVertex;
    cout<<"\nEnter starting vertex: ";
    cin>>startVertex;

    //Djikstra

    int dist[numVertex],parent[numVertex];

    for(int i=0;i<numVertex;i++)
    {
        dist[i]=inf;
        parent[i]=NULL;
    }

    dist[startVertex]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

    pq.push({0,startVertex});

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

    for(int i=0;i<numVertex;i++)
        cout<<"\nDistance of vertex "<<i<<" from vertex "<<startVertex<<" is "<<dist[i];

    return 0;
}