#include <bits/stdc++.h>
using namespace std;

void dfs(int node,vector<int>&vis,stack<int>&st,vector<vector<int>>&adj){
    vis[node] = 1;
    for (int i = 0; i < adj[node].size(); i++){
        if(!vis[adj[node][i]]){
            dfs(adj[node][i],vis,st,adj);
        }
    }
    st.push(node);
}

vector<int>topoSort(vector<vector<int>>&adj){
    vector<int>vis(adj.size(),0);
    stack<int>st;
    for(int i = 0;i<adj.size();i++){
        if(!vis[i]){
            dfs(i,vis,st,adj);
        }
    }
    vector<int>result;
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    return result;
}

int main() {
    vector<vector<int>> adj = {
        {},         
        {2, 6},     
        {3, 4},     
        {},         
        {5, 7},     
        {8},        
        {7, 9},     
        {8},        
        {},
        {}
    };

    vector<int>result = topoSort(adj);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}