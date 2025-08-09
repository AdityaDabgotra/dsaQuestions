#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>>& arr, vector<bool>& vis, int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int neighbor : arr[curr]) {
            if (!vis[neighbor]) {
                q.push(neighbor);
                vis[neighbor] = true;
            }
        }
    }
}

int findCircleNum(vector<vector<int>>& isC) {
    int v = isC.size();
    vector<bool> visited(v, false);
    int count = 0;
    for (int i = 1; i < v; i++) {
        if (!visited[i]) {
            bfs(isC, visited, i);
            count++;
        }
    }
    return count;
}

int main() {
    vector<vector<int>> adj(10);

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

    int number = findCircleNum(adj);
    cout << "The Number of Provinces are " << number;
    return 0;
}
