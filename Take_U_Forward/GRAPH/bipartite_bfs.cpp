#include<bits/stdc++.h>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    vector<int> colors(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++) {
        if (colors[i] == -1) {
            queue<pair<int, int>> q;
            q.push({i, 0});
            colors[i] = 0;
            
            while (!q.empty()) {
                auto [node, color] = q.front();
                q.pop();
                
                for (int neighbor : graph[node]) {
                    if (colors[neighbor] == -1) {
                        colors[neighbor] = 1 - color;
                        q.push({neighbor, 1 - color});
                    } else if (colors[neighbor] == color) {
                        return false;
                    }
                }
            }
        }
    }    
    return true;
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

    if(isBipartite(adj)){
        cout<<"The graph is Bipartite";
    }
    else{
        cout<<"The graph is NOT Bipartite";
    }
      
    return 0;
}