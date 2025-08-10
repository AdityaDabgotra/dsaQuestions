#include <bits/stdc++.h>
using namespace std;

bool detect(vector<vector<int>>& arr, int s, vector<bool>& visited) {
    stack<pair<int,int>>st;  //{node,parent}
    st.push({s,-1});
    visited[s] = true;
    while(!st.empty()){
        auto [node,parent] = st.top();
        st.pop();
        for (int i = 0; i < arr[node].size() ; i++){
            if(arr[node][i] == parent)continue;
            if(!visited[arr[node][i]]){
                st.push({arr[node][i],node});
                visited[arr[node][i]] = true;
            }
            else return true;
        }
    }
    return false;
}

bool cycle(vector<vector<int>>& arr) {
    vector<bool> visited(arr.size(), false);
    for (int i = 0; i < arr.size(); i++) {
        if (!visited[i]) {
            if (detect(arr, i, visited)) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> adj(10);

    adj[1] = {2, 6};
    adj[2] = {1, 3, 4};
    adj[3] = {2};
    adj[4] = {2, 5, 7};
    adj[5] = {4, 8};
    adj[6] = {1, 7, 9};
    adj[7] = {4, 6, 8};
    adj[8] = {5, 7};
    adj[9] = {6};

    if (cycle(adj))
        cout << "The Graph has a Cycle";
    else
        cout << "The graph does not have a Cycle";

    return 0;
}