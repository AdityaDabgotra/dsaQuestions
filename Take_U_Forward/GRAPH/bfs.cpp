#include<bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int s) {
    vector<int> result;
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        result.push_back(curr);
        for (int neighbor : graph[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return result;
}

int main(){
    vector<vector<int>>adj(10);

    adj[1].push_back(2);
    adj[1].push_back(6);

    adj[2].push_back(1);    
    adj[2].push_back(3);    
    adj[2].push_back(4);

    adj[3].push_back(2);

    adj[4].push_back(2);    
    adj[4].push_back(5);    
    adj[4].push_back(7);

    adj[5].push_back(4);    
    adj[5].push_back(8);

    adj[6].push_back(1);    
    adj[6].push_back(7);    
    adj[6].push_back(9);

    adj[7].push_back(4);    
    adj[7].push_back(6);    
    adj[7].push_back(8);

    adj[8].push_back(5);    
    adj[8].push_back(7);

    adj[9].push_back(6);

    int start;
    cout<<"Enter Starting Point:\t";
    cin>>start;

    vector<int>result = bfs(adj,start);
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
      
    return 0;
}