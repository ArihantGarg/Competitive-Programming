#include<bits/stdc++.h>
using namespace std;

int main()
{
    int numVertex;
    cout<<"Enter number of vertices : ";
    cin>>numVertex;

    int adj[numVertex][numVertex];

    for(int i=0;i<numVertex;i++)
        for(int j=0;j<numVertex;j++)
        {
            if(i==j)
                adj[i][j]=0;
            else
                adj[i][j]=1e9;
        }

    int numEdge;
    cout<<"Enter number of edges : ";
    cin>>numEdge;

    cout<<"Enter all edges :\n";

    for(int i=0;i<numEdge;i++)
    {
        int u,v,weight;
        cin>>u>>v>>weight;

        //Assuming Directed graph

        adj[u][v]=weight;
    }

    //Floyd Warshall

    for(int k=0;k<numVertex;k++)
        for(int i=0;i<numVertex;i++)
            for(int j=0;j<numVertex;j++)
            {
                if(adj[i][j]>adj[i][k]+adj[k][j])
                    adj[i][j]=adj[i][k]+adj[k][j];
            }

    for(int i=0;i<numVertex;i++)
    {
        cout<<"\n";
        for(int j=0;j<numVertex;j++)
        {
            if(adj[i][j]==1e9)
                cout<<"INF ";
            else
                cout<<adj[i][j]<<" ";
        }
    }

    return 0;
}