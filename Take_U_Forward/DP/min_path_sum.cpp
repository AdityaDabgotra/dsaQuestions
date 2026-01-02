#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach using recursion
int calculate(vector<vector<int>>& grid,int i,int j){
    if(i >= grid.size() || j >= grid[0].size())return INT_MAX;
    if(i == grid.size()-1 && j == grid[0].size()-1){
        return grid[i][j];
    }
    int right = calculate(grid,i,j+1);
    int down = calculate(grid,i+1,j);
    return grid[i][j] + min(right,down);
}
int minPathSum1(vector<vector<int>>& grid){
    return calculate(grid,0,0);
}

// Optimised Solution using Memoisation
int find(vector<vector<int>>& grid,vector<vector<int>>&dp,int i,int j){
    if(i >= grid.size() || j >= grid[0].size())return INT_MAX;

    if(i == grid.size()-1 && j == grid[0].size()-1){
        return grid[i][j];
    }
    if(dp[i][j] != INT_MAX)return dp[i][j];
    int right = find(grid,dp,i,j+1);
    int down = find(grid,dp,i+1,j);

    int best = min(right, down);
    if (best == INT_MAX) return dp[i][j] = INT_MAX;

    return dp[i][j] = grid[i][j] + best;
}
int minPathSum2(vector<vector<int>>& grid){
    vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),INT_MAX));
    return find(grid,dp,0,0);
}

// Optimised Solution using Tabulation
int minPathSum3(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
    dp[0][0] = grid[0][0];
    for(int i= 1;i<m;i++){
        dp[i][0] = grid[i][0]+dp[i-1][0];
    }
    for(int i= 1;i<n;i++){
        dp[0][i] = grid[0][i] + dp[0][i-1];
    }
    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            dp[i][j] = min(dp[i][j],grid[i][j] + min(dp[i-1][j],dp[i][j-1]));
        }
    }
    return dp[m-1][n-1];
}
// Space Optimisation over Tabulation
int minPathSum3(vector<vector<int>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vector<int>dp(n,INT_MAX);
    dp[0] = grid[0][0];

    for(int i = 1;i<m;i++){
        for(int j = 1;j<n;j++){
            dp[j] = min(dp[j],grid[i][j] + min(dp[j],dp[j-1]));
        }
    }
    return dp[n-1];
}

int main(){
    int m,n;
    cout<<"Enter the number of rows in matrix:\t";
    cin>>m;
    cout<<"Enter the number of cols in matrix:\t";
    cin>>n;
    vector<vector<int>>grid(m,vector<int>(n));
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin>>grid[i][j];
        }
        
    }
    cout<<"The minimum path sum is "<<minPathSum3(grid);
    return 0;
}