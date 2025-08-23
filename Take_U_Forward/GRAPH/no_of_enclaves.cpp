#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>&board,vector<vector<int>>&vis,int i,int j){
    int n = board.size();
    int m = board[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    vis[i][j] = 1;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();
        if( x+1< n && board[x+1][y] == 1 && !vis[x+1][y]){
            q.push({x+1,y});
            vis[x+1][y] = 1;
        }
        if( x-1 >= 0 && board[x-1][y] == 1 && !vis[x-1][y]){
            q.push({x-1,y});
            vis[x-1][y] = 1;
        }
        if(y+1 < m && board[x][y+1] == 1 && !vis[x][y+1]){
            q.push({x,y+1});
            vis[x][y+1] = 1;
        }
        if(y-1 >= 0 && board[x][y-1] == 1 && !vis[x][y-1]){
            q.push({x,y-1});
            vis[x][y-1] = 1;
        }
    }
}
int enclave(vector<vector<char>>& board) {
    int n = board.size();
    int m = board[0].size();

    vector<vector<int>>vis(n,vector<int>(m,0));
    for(int j = 0;j<m;j++){
        if(!vis[0][j] && board[0][j] == 1){
            bfs(board,vis,0,j);
        }
        if(!vis[n-1][j] && board[n-1][j] == 1){
            bfs(board,vis,n-1,j);
        }
    }
    for(int i = 0;i<n;i++){
        if(!vis[i][0] && board[i][0] == 1){
            bfs(board,vis,i,0);
        }
        if(!vis[i][m-1] && board[i][m-1] == 1){
            bfs(board,vis,i,m-1);
        }
    }
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(board[i][j] == 1 && !vis[i][j]){
                count++;
            }
        }
    }
}

int main(){
    int rows,cols;
    cout<<"Enter the row Size :\t";
    cin>>rows;
    cout<<"Enter the cols Size :\t";
    cin>>cols;
    vector<vector<char>> adj(rows,vector<char>(cols));
    cout<<"Enter the Symbol:\n";
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin>>adj[i][j];
        }
        
    }
    int result = enclave(adj);
    cout<<"The Number of Enclaves are :\t"<<result;
    return 0;
}
