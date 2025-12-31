#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach using recursion
int uniquePaths1(int m, int n) {
    if(m <=0 || n <= 0)return 0;

    if(m-1 == 0 && n-1 == 0)return 1;

    int left = uniquePaths1(m,n-1);
    int up = uniquePaths1(m-1,n);

    return left + up;
}

// Optimised using Memoisation
int solver(vector<vector<int>>& dp, int i, int j) {
    if (i < 0 || j < 0) return 0;

    if (i == 0 && j == 0) return 1;

    if (dp[i][j] != -1) return dp[i][j];

    int left = solver(dp, i, j - 1);
    int up   = solver(dp, i - 1, j);

    return dp[i][j] = left + up;
}

int uniquePaths2(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solver(dp, m - 1, n - 1);
}

// Optimised using bottom up Tabulation
int uniquePaths3(int m, int n) {
    vector<int> dp(n, 1);

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] = dp[j] + dp[j - 1];
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
    cout<<"The total number of paths are:\t"<<uniquePaths3(m,n);
    return 0;
}