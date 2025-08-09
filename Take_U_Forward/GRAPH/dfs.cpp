#include<bits/stdc++.h>
using namespace std;

vector<int> dfs(vector<vector<int>>& graph, int s) {
    vector<int> result;
    vector<bool>visited(graph.size(),false);
    stack<int>st;
    st.push(s);
    visited[s] = true;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        result.push_back(curr);
        for (int i = graph[curr].size()-1; i >=0 ; i--){
            if(!visited[graph[curr][i]]){
                st.push(graph[curr][i]);
                visited[graph[curr][i]] = true;
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

    vector<int>result = dfs(adj,start);
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
      
    return 0;
}