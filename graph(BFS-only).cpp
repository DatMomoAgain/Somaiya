#include<iostream>
#include<unordered_map>
#include<vector>
#include<queue>
using namespace std;

/*void dfs(int index,bool visited[],int** graph, int vertices)
{

    visited[index]=true;
    cout<<index<<" ";
    for(auto i:graph[index])
    {
        
        if(!visited[i])
        {
            dfs(i,visited,graph);
        }   
    }
}*/

void bfs(int index,bool visited[],int** graph, int vertices)
{
    queue<int>queue1;
    queue1.push(index);
    while(!queue1.empty())
    {
        int node = queue1.front();
        queue1.pop();
        cout<<node<<" ";

        for(int i=0; i<vertices; i++)
        {
            if(graph[node][i]==1)
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    queue1.push(i);
                }
            }
        }
    }  
}
int main()
{
    
    cout<<"Enter number of vertices: ";
    int edges;
    int vertices;
    cin>>vertices;
    cout<<"Enter number of edges: ";
    cin>>edges;

    //initialising 2d array for graph
    int **graph = new int*[vertices];
    for(int i=0; i<vertices; i++)
    {
        graph[i] = new int[vertices];
    }
    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            graph[i][j]=0;
        }
    }

    for(int i=0; i<vertices; i++)
    {
        for(int j=0; j<vertices; j++)
        {
            graph[i][j]=0;
        }
    }
    for (int i = 0; i < vertices; i++)
    {
        cout<<"Enter no. of edges for vertice "<<i<<": ";
        int n;
        cin>>n;
        for(int j=0; j<n; j++)
        {
            int v1 = i;
            int v2;
            cout<<"Enter vertex edge connects to: ";
            cin>>v2;
            graph[v1][v2] = 1;            
        }
    }

    bool visited[vertices];
    for(int i=0;i<vertices;i++)
    {
        visited[i]=false;
    }

    //cout<<"\nDFS Traversal:\n";
    //dfs(0,visited,graph);

    for(int i=0;i<vertices;i++)
    {
        visited[i]=false;
    }
    
    cout<<"\nBFS Traversal:\n";
    cout<<"Enter starting vertex: ";
    int t1;
    cin>>t1;
    visited[t1]=true;
    bfs(t1,visited,graph,vertices);
}
