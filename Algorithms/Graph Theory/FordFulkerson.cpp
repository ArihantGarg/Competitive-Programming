#include<bits/stdc++.h>
using namespace std;

// Edmond's Karp Algorithm (BFS version of Ford Fulkerson)
// O (V*E*(V+E)) time complexity -> O(VE^2) 

int numVertex;
int numEdge;
int graph[1000][1000]={};
int rgraph[1000][1000]={};
int parent[1000];


bool bfs(int s,int t)
{
    bool visited[1000]={};

    queue<int> q;
    q.push(s);
    visited[s]=1;
    parent[s]=-1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < numVertex; v++) {
            if (visited[v] == false && rgraph[u][v] > 0) 
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }

    if(visited[t])
        return 1;
    return 0;
}


int ford(int s,int t)
{
    int maxflow=0;

    while(bfs(s,t))
    {
        int pathflow=1e9;

        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            pathflow=min(pathflow,rgraph[u][v]);
        }


        for(int v=t;v!=s;v=parent[v])
        {
            int u=parent[v];
            rgraph[u][v]-=pathflow;
            rgraph[v][u]+=pathflow;
        }

        maxflow+=pathflow;
    }

    return maxflow;
}


int main()
{
    cout<<"Enter number of vertices : ";
    cin>>numVertex;

    cout<<"Enter number of edges : ";
    cin>>numEdge;

    cout<<"Enter all edges : ";
    for(int i=0;i<numEdge;i++)
    {
        int a,b,weight;
        cin>>a>>b>>weight;

        graph[a][b]=weight;
        rgraph[a][b]=weight;
    }

    cout<<"Enter indices of start and end vertex : ";
    int start,end;

    cin>>start>>end;

    cout<<"\nMaximum possible flow is : "<<ford(start,end);


    return 0;
}