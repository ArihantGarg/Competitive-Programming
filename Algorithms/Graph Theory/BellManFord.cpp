#include<bits/stdc++.h>
using namespace std;
#define inf 1e9

int main()
{
    //Input graph

    int numVertex;
    // cout<<"Enter number of vertices: ";
    cin>>numVertex;

    int numEdge;
    // cout<<"Enter number of edges: ";
    cin>>numEdge;

    vector<pair<int,int>> adj[numVertex];

    for(int i=0;i<numEdge;i++)
    {
        // cout<<"\nEnter edge vertices and weight: \n";
        int u,v,weight;
        cin>>u>>v>>weight;

        adj[u].push_back({v,weight});
    }

    int startVertex;
    //cout<<"\nEnter starting vertex: ";
    cin>>startVertex;

    //BellManFord

    int dist[numVertex];

    for(int i=0;i<numVertex;i++)
        dist[i]=1e9;

    dist[startVertex]=0;

    for(int p=0;p<numVertex-1;p++)
    {
        for(int i=0;i<numVertex;i++)
            for(auto x:adj[i])
            {
                if(dist[x.first]>x.second+dist[i])
                {
                    dist[x.first]=x.second+dist[i];
                }
            }
    }

    int flag=0;

    for(int i=0;i<numVertex;i++)
            for(auto x:adj[i])
            {
                    if(dist[x.first]>x.second+dist[i])
                    {
                        flag=1;
                    }
            }

    if(flag)
    {
        cout<<"Negative cycle";
    }
    else
    {
        for(int i=0;i<numVertex;i++)
        {
            cout<<i<<"->"<<dist[i]<<"\n";
        }
    }

    return 0;
}