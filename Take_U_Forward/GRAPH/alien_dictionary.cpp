#include<bits/stdc++.h>
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

vector<char>decode(vector<string>&dict,int k){
    vector<vector<int>>adj(k);
    for (int i = 0; i < dict.size()-1; i++){
        int size = min(dict[i].size(),dict[i+1].size());
        for (int j = 0; j < size; j++){
            if(dict[i][j] != dict[i+1][j]){
                adj[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                break;
            }
        }
    }
    vector<int>result = topoSort(adj);
    vector<char>ans;
    for (int i = 0; i < result.size(); i++){
        ans.push_back(result[i] + 'a');
    }
    return ans;
}


int main(){

    vector<string>dict = {"baa","abcd","abca","cab","cad"};
    vector<char> ans = decode(dict,4);
    for (int i = 0; i < ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}