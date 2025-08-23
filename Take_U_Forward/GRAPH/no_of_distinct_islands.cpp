#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> traverse(vector<vector<int>>&arr,int i,int j){
    vector<pair<int,int>>result;
    int rows = arr.size();
    int cols = arr[0].size();
    queue<pair<int,int>>q;
    q.push({i,j});
    result.push_back({0,0});
    arr[i][j] = -1;
    while(!q.empty()){
        auto curr = q.front();
        q.pop();
        if(curr.second+1 < cols && arr[curr.first][curr.second+1] == 1){
            q.push({curr.first,curr.second+1});
            result.push_back({curr.first-i,curr.second+1-j});
            arr[curr.first][curr.second+1] = -1;
        }
        if(curr.second+1 < cols && curr.first+1 < rows && arr[curr.first+1][curr.second+1] == 1){
            q.push({curr.first+1,curr.second+1});
            result.push_back({curr.first+1-i,curr.second+1-j});
            arr[curr.first+1][curr.second+1] = -1;
        }
        if(curr.first+1 < rows && arr[curr.first+1][curr.second] == 1){
            q.push({curr.first+1,curr.second});
            result.push_back({curr.first+1-i,curr.second-j});
            arr[curr.first+1][curr.second] = -1;
        }
        if(curr.second-1 >= 0 && curr.first+1 < rows && arr[curr.first+1][curr.second-1] == 1){
            q.push({curr.first+1,curr.second-1});
            result.push_back({curr.first+1-i,curr.second-1-j});
            arr[curr.first+1][curr.second-1] = -1;
        }
        if(curr.second+1 < cols && curr.first-1 >= 0 && arr[curr.first-1][curr.second+1] == 1){
            q.push({curr.first-1,curr.second+1});
            result.push_back({curr.first-1-i,curr.second+1-j});
            arr[curr.first-1][curr.second+1] = -1;
        }
    }
    return result;
}

int islands(vector<vector<int>>arr){
    int count = 0;
    set<vector<pair<int,int>>>s;
    for (int i = 0; i < arr.size(); i++){
        for (int j = 0; j < arr[0].size(); j++){
            if(arr[i][j] == 1){
                vector<pair<int,int>> result = traverse(arr,i,j);
                if(s.find(result) == s.end()){
                    count++;
                    s.insert(result);
                }
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
    cout << "The Number of Distinct Islands are " << number;
    return 0;
}
