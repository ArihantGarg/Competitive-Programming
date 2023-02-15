#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Adjacency list

    int numVertex;
    cin>>numVertex;

    vector<int> adj[numVertex];

    int numEdge;
    cin>>numEdge;

    for(int i=0;i<numEdge;i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a); //If directed,remove this
    }

    //BFS

    queue<int> q;
    int visited[numVertex];
    for(int i=0;i<numVertex;i++)
        visited[i]=0;

    int startVertex;
    cin>>startVertex;

    visited[startVertex]=1;
    q.push(startVertex);

    while(!q.empty())
    {
        int currentVertex=q.front();
        cout<<currentVertex<<" ";
        q.pop();

        for(auto i:adj[currentVertex])
        {
            if(visited[i]==0)
            {
                visited[i]=1;
                q.push(i);
            }
        }

    }
}