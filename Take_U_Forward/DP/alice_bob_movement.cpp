#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
int path1(vector<vector<int>> &grid, int i, int j1, int j2) {
    int n = grid.size();
    int m = grid[0].size();

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return INT_MIN;

    if (i == n) return 0;

    int value;
    if (j1 == j2) value = grid[i][j1];
    else value = grid[i][j1] + grid[i][j2];

    int max_result = INT_MIN;

    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int result = path1(grid, i + 1, j1 + dj1, j2 + dj2);
            max_result = max(max_result, result);
        }
    }

    if (max_result == INT_MIN) return INT_MIN;
    return value + max_result;
}

// Memoization Approach
int traverse(vector<vector<int>> &grid, int i, int j1, int j2,vector<vector<vector<int>>> &dp){
    int n = grid.size();
    int m = grid[0].size();

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)return INT_MIN;

    if (i == n) return 0;

    if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

    int value;
    if (j1 == j2) value = grid[i][j1];
    else value = grid[i][j1] + grid[i][j2];

    int max_result = INT_MIN;

    for (int dj1 = -1; dj1 <= 1; dj1++) {
        for (int dj2 = -1; dj2 <= 1; dj2++) {
            int next = traverse(grid, i + 1, j1 + dj1, j2 + dj2, dp);
            max_result = max(max_result, next);
        }
    }

    if (max_result == INT_MIN) return dp[i][j1][j2] = INT_MIN;

    return dp[i][j1][j2] = value + max_result;
}

int path2(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    return traverse(grid, 0, 0, m - 1, dp);
}


// Tabulation Approach
int path3(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    // Base case (last row)
    for (int j1 = 0; j1 < m; j1++) {
        for (int j2 = 0; j2 < m; j2++) {
            if (j1 == j2)
                dp[n - 1][j1][j2] = grid[n - 1][j1];
            else
                dp[n - 1][j1][j2] =
                    grid[n - 1][j1] + grid[n - 1][j2];
        }
    }

    // Fill from bottom to top
    for (int i = n - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {

                int max_result = INT_MIN;

                for (int dj1 = -1; dj1 <= 1; dj1++) {
                    for (int dj2 = -1; dj2 <= 1; dj2++) {

                        int new_j1 = j1 + dj1;
                        int new_j2 = j2 + dj2;

                        if (new_j1 >= 0 && new_j1 < m && new_j2 >= 0 && new_j2 < m) {
                            max_result = max(max_result,dp[i + 1][new_j1][new_j2]);
                        }
                    }
                }

                int value;
                if (j1 == j2) value = grid[i][j1];
                else value = grid[i][j1] + grid[i][j2];

                dp[i][j1][j2] = value + max_result;
            }
        }
    }

    return dp[0][0][m - 1];
}

int main() {
    int row, cols;
    cout << "Enter the no of rows: ";
    cin >> row;
    cout << "Enter the no of cols: ";
    cin >> cols;
    vector<vector<int>> grid(row, vector<int>(cols));
    cout << "Enter the elements:\n";
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> grid[i][j];
        }
    }
    cout << "\nBrute Force Answer: "
         << path1(grid, 0, 0, cols - 1) << endl;

    cout << "Memoization Answer: "
         << path2(grid) << endl;

    cout << "Tabulation Answer: "
         << path3(grid) << endl;

    return 0;
}