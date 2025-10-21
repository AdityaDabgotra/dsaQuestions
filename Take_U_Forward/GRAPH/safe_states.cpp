#include <bits/stdc++.h>
using namespace std;

bool dfsCheck(int node,vector<vector<int>>&adj,vector<int>&vis,vector<int>&pathvis,vector<int>&check){
    vis[node] = 1;
    pathvis[node] = 1;

    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfsCheck(it,adj,vis,pathvis,check) == true){
                return true;
            }
        }
        else if(pathvis[it]){
            return true;
        }
    }
    check[node] = 1;
    pathvis[node] = 0;
    return false;
}
vector<int>safeNode(vector<vector<int>>&adj){
    vector<int>vis(adj.size(),0);
    vector<int>pathvis(adj.size(),0);
    vector<int>checkV(adj.size(),0);
    vector<int>ans;
    for (int i = 0; i < adj.size(); i++){
        if(!vis[i]){
            dfsCheck(i,adj,vis,pathvis,checkV);
        }
    }
    for(int i = 0;i<adj.size();i++){
        if(checkV[i] == 1){
            ans.push_back(i);
        }
    }
    return ans;
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

    vector<int>result = safeNode(adj);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}