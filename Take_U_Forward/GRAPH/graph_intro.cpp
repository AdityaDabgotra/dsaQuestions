#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cout<<"Enter the Number of vertices:\t";
    cin>>n;
    cout<<"Enter the Number of Edges:\t";
    cin>>m;
    int adj[n+1][m+1];
    for (int i = 0; i < m; i++)
    {
        int u,v;
        cout<<"Enter the connection:\t";
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    return 0;
}