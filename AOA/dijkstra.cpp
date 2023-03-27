#include <bits/stdc++.h>
using namespace std;
#define int long long int

int minvert(vector<int> dist, vector<bool> visit)
{
    int min = INT_MAX;
    int minind;
    for(int i=0; i<dist.size(); i++)
    {
        if(min>dist[i] && !visit[i])
        {
            min = dist[i];
            minind = i;
        }
    }
    return minind;
}

void dijkstra(vector<vector<int>> v, int s)
{
    vector<int> dist(v.size());
    vector<bool> visit(v.size());
    vector<int> prev(v.size());
    prev[s] = -1;

    for(int i=0; i<v.size(); i++)
    {
        dist[i] = INT_MAX;
        visit[i] = false;
    }

    dist[s] = 0;

    for(int i=0; i<v.size()-1; i++)
    {
        int vmin = minvert(dist, visit);

        visit[vmin] = true;
        for(int j=0; j<v.size(); j++)
        {
            if(v[vmin][j]+dist[vmin]<dist[j] && !visit[j])
            {
                dist[j] = v[vmin][j]+dist[vmin];
                prev[j] = vmin;
            }
        }
    }

    cout<<endl<<"ANS:"<<endl;
    cout<<"route \t\t distance"<<endl;
    for(int i=0; i<dist.size(); i++)
    {
        int t=i;
        vector<int> temp;
        temp.push_back(i);
        while(prev[t]!=-1)
        {
            temp.push_back(prev[t]);
            t=prev[t];
        }

        for(int j=temp.size()-1; j>=0; j--)
        {
            cout<<temp[j]<<'-';
        }
        cout<<"\t\t"<<dist[i]<<endl;
    }
}

int32_t main()
{
    cout<<"Enter no. of vertices and no. of edges: ";
    int n,e;
    cin>>n>>e;

    vector<vector<int>> v;
    for(int i=0; i<n; i++)
    {
        vector<int> t;
        for(int j=0; j<n; j++)
        {
            t.push_back(INT_MAX);
        }
        v.push_back(t);
    }

    cout<<"Enter (vertex1, vertex2 to which it connects, weight): "<<endl;
    for(int i=0; i<e; i++)
    {
        int v1, v2, w;
        cin>>v1>>v2>>w;
        v[v1][v2]=w;
    }

    cout<<"Enter source: ";
    int s;
    cin>>s;

    dijkstra(v,s);
}

/*
0 1 50
1 2 10
0 3 10
1 3 15
3 0 20
0 2 45
4 1 20
3 4 15
2 4 30
4 2 35
 
*/
