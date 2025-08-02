#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the Number of vertices:\t";
    cin>>n;
    cout<<"Enter the Number of Edges:\t";
    cin>>m;

    //adjacency matrix 
    int adj[n+1][m+1];
    for (int i = 0; i < m; i++){
        int u,v;
        cout<<"Enter the connection:\t";
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    // adjacency list
    vector<int>adj2[n+1];
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cout<<"Enter the connection:\t";
        cin>>u>>v;
        adj2[v].push_back(u);
        adj2[u].push_back(v);
    }
    
    
    return 0;
}