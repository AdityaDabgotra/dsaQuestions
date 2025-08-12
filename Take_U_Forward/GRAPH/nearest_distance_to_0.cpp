#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> distance(vector<vector<int>>& mat) {
    int n = mat.size(), m = mat[0].size();
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if (dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }

    return dist;
}

int main(){
    int rows,cols;
    cout<<"Enter the row Size :\t";
    cin>>rows;
    cout<<"Enter the cols Size :\t";
    cin>>cols;
    vector<vector<int>> adj(rows,vector<int>(cols));
    cout<<"Enter the Elements:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin>>adj[i][j];
        }
        
    }
    
    vector<vector<int>>result = distance(adj);
    cout<<"The Distance to nearest 0 is:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
