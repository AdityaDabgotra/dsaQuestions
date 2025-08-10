#include <bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>>& grid,vector<pair<int,int>>&cords) {
    int t = 0;
    bool rotten;
    queue<pair<int, int>> q;
    for(int i = 0;i<cords.size();i++){
        q.push(cords[i]);
    }
    while (!q.empty()) {
        rotten = false;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto curr = q.front();
            q.pop();
            if (curr.second + 1 < grid[0].size() &&
                grid[curr.first][curr.second + 1] == 1) {
                q.push({curr.first, curr.second + 1});
                grid[curr.first][curr.second + 1] = 2;
                rotten = true;
            }
            if (curr.second - 1 >= 0 &&
                grid[curr.first][curr.second - 1] == 1) {
                q.push({curr.first, curr.second - 1});
                grid[curr.first][curr.second - 1] = 2;
                rotten = true;
            }
            if (curr.first - 1 >= 0 &&
                grid[curr.first - 1][curr.second] == 1) {
                q.push({curr.first - 1, curr.second});
                grid[curr.first - 1][curr.second] = 2;
                rotten = true;
            }
            if (curr.first + 1 < grid.size() &&
                grid[curr.first + 1][curr.second] == 1) {
                q.push({curr.first + 1, curr.second});
                grid[curr.first + 1][curr.second] = 2;
                rotten = true;
            }
        }
        if(rotten)t++;
    }
    return t;
}

int orangesRotting(vector<vector<int>>& grid) {
    int time = 0;
    vector<pair<int,int>>cords;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 2) {
                cords.push_back({i,j});
            }
        }
    }
    time = bfs(grid,cords);
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                return -1;
            }
        }
    }    
    return time;
}

int main(){
    int rows, cols;
    cout << "Enter the row Size :\t";
    cin >> rows;
    cout << "Enter the cols Size :\t";
    cin >> cols;
    vector<vector<int>> adj(rows, vector<int>(cols));
    cout << "Enter the Elements:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin >> adj[i][j];
        }
    }
    int result = orangesRotting(adj);
    cout<<"The Total time taken to rot all oranges is "<<result;
    
    return 0;
}