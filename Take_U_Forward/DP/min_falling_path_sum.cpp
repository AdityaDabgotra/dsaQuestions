#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach using recursion
int path(vector<vector<int>>&matrix,int i,int j){
    if(i >= matrix.size() || j >= matrix[0].size() || j < 0)return INT_MAX;

    int down = path(matrix,i+1,j);
    int down_right = path(matrix,i+1,j+1);
    int down_left = path(matrix,i+1,j-1);

    int best = min({down,down_right,down_left});
    if(best == INT_MAX)return matrix[i][j];

    return matrix[i][j] + best;
}
int minFallingPathSum1(vector<vector<int>>& matrix) {
    int ans = INT_MAX;
    for (int j = 0; j < matrix[0].size(); j++) {
        ans = min(ans, path(matrix, 0, j));
    }
    return ans;
}

// Optimised approach using memoisation
int find(vector<vector<int>>&matrix,vector<vector<int>>&dp,int i,int j){
    if(i >= matrix.size() || j >= matrix[0].size() || j < 0)return INT_MAX;

    if(dp[i][j] != INT_MAX)return dp[i][j];

    int down = find(matrix,dp,i+1,j);
    int down_right = find(matrix,dp,i+1,j+1);
    int down_left = find(matrix,dp,i+1,j-1);

    int best = min({down,down_right,down_left});
    if(best == INT_MAX)return matrix[i][j];

    return dp[i][j] = matrix[i][j] + best;
}
int minFallingPathSum2(vector<vector<int>>& matrix) {
    int ans = INT_MAX;
    int m = matrix.size();
    int n = matrix[0].size();

    vector<vector<int>>dp(m,vector<int>(n,INT_MAX));

    for (int j = 0; j < matrix[0].size(); j++) {
        ans = min(ans, find(matrix,dp, 0, j));
    }
    return ans;
}

// optimised solution using Tabulation
int minFallingPathSum3(vector<vector<int>> matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = m-2; i >= 0; i--) {
        for (int j = 0; j < n; j++){
            if(j == 0){
                matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j+1]);
            }
            else if(j == n-1){
                matrix[i][j] += min(matrix[i+1][j],matrix[i+1][j-1]);
            }
            else{
                matrix[i][j] += min({matrix[i+1][j],matrix[i+1][j+1],matrix[i+1][j-1]});
            }
        }
    }
    return *min_element(matrix[0].begin(),matrix[0].end());
}

// Space Optimised over Tabulation
int minFallingPathSum3(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int> dp = matrix[m - 1];

    for (int i = m - 2; i >= 0; i--) {
        vector<int> newdp(n, INT_MAX);

        for (int j = 0; j < n; j++) {
            if (j > 0) newdp[j] = min(newdp[j], matrix[i][j] + dp[j - 1]);

            newdp[j] = min(newdp[j], matrix[i][j] + dp[j]);

            if (j + 1 < n) newdp[j] = min(newdp[j], matrix[i][j] + dp[j + 1]);
        }
        dp = newdp;
    }
    return *min_element(dp.begin(), dp.end());
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
    cout<<"The minimum path sum is "<<minFallingPathSum1(grid);
    return 0;
}