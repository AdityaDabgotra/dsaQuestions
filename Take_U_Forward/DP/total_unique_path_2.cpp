#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach using recursion
int solved(vector<vector<int>>&obs,int m,int n){
    if( m < 0 || n < 0)return 0;
    if(obs[m][n] == 1)return 0;
    if(m == 0 && n == 0) return 1;
    
    int left = 0,up = 0;
    up = solved(obs,m-1,n);
    left = solved(obs,m,n-1);
    return up + left;
}
int uniquePathsWithObstacles1(vector<vector<int>>& obs) {
    int m = obs.size();
    int n = obs[0].size();
    return solved(obs,m-1,n-1);
}

// Optimised solution using Memoisation
int solve(vector<vector<int>>&obs,vector<vector<int>>&dp,int m,int n){
    if( m < 0 || n < 0)return 0;
    if(obs[m][n] == 1)return 0;
    if(m == 0 && n == 0) return 1;
    if(dp[m][n] != -1) return dp[m][n];
    
    int left = 0,up = 0;
    up = solve(obs,dp,m-1,n);
    left = solve(obs,dp,m,n-1);
    return dp[m][n] = up + left;
}
int uniquePathsWithObstacles2(vector<vector<int>>& obs) {
    int m = obs.size();
    int n = obs[0].size();
    vector<vector<int>>dp(m,vector<int>(n,-1));
    return solve(obs,dp,m-1,n-1);
}

// Optimised solution using Tabultion
int uniquePathsWithObstacles3(vector<vector<int>>& obs) {
    int m = obs.size();
    int n = obs[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if (obs[0][0] == 1) return 0;
    dp[0][0] = 1;

    for (int i = 1; i < m; i++) {
        if (obs[i][0] == 0)
            dp[i][0] = dp[i - 1][0];
    }
    for (int j = 1; j < n; j++) {
        if (obs[0][j] == 0)
            dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obs[i][j] == 0)
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[m - 1][n - 1];
}

// Space Optimised solution of Tabulation 
int uniquePathsWithObstacles4(vector<vector<int>>& obs){
    int m = obs.size();
    int n = obs[0].size();
    vector<int> dp(n, 0);

    dp[0] = (obs[0][0] == 0);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (obs[i][j] == 1) {
                dp[j] = 0;
            }
            else if (j > 0) {
                dp[j] += dp[j - 1];
            }
        }
    }
    return dp[n - 1];
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
    
    return 0;
}