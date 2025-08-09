#include <bits/stdc++.h>
using namespace std;

void traverse(vector<vector<int>>&arr,int i,int j){
    int rows = arr.size();
    int cols = arr[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    arr[i][j] = -1;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(curr.second+1 < cols && arr[curr.first][curr.second+1] == 1){
            q.push({curr.first,curr.second+1});
            arr[curr.first][curr.second+1] = -1;
        }
        if(curr.second+1 < cols && curr.first+1 < rows && arr[curr.first+1][curr.second+1] == 1){
            q.push({curr.first+1,curr.second+1});
            arr[curr.first+1][curr.second+1] = -1;
        }
        if(curr.first+1 < rows && arr[curr.first+1][curr.second] == 1){
            q.push({curr.first+1,curr.second});
            arr[curr.first+1][curr.second] = -1;
        }
        if(curr.second-1 >= 0 && curr.first+1 < rows && arr[curr.first+1][curr.second-1] == 1){
            q.push({curr.first+1,curr.second-1});
            arr[curr.first+1][curr.second-1] = -1;
        }
        if(curr.second+1 < cols && curr.first-1 >= 0 && arr[curr.first-1][curr.second+1] == 1){
            q.push({curr.first-1,curr.second+1});
            arr[curr.first-1][curr.second+1] = -1;
        }
    }
}

int islands(vector<vector<int>>arr){
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[0].size(); j++){
            if(arr[i][j] == 1){
                traverse(arr,i,j);
                count++;
            }
        }
    }
    return count;
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
    
    int number = islands(adj);
    cout << "The Number of Islands are " << number;
    return 0;
}
