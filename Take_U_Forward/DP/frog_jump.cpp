#include <bits/stdc++.h>
using namespace std;

// using normal DP
int jump1(int n, vector<int>& arr, vector<int>& idx) {
    if (n == 0) return 0;

    if (idx[n] != -1) return idx[n];

    int one_left = abs(arr[n] - arr[n - 1]) + jump1(n - 1, arr, idx);

    int two_left = INT_MAX;
    if (n > 1) two_left = abs(arr[n] - arr[n - 2]) + jump1(n - 2, arr, idx);

    return idx[n] = min(one_left, two_left);
}

// Using Bottom up DP (Tabulation)
int jump2(int n, vector<int>& arr){
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int one = dp[i-1] + abs(arr[i] - arr[i-1]);
        int two = INT_MAX;
        if (i > 1) two = dp[i-2] + abs(arr[i] - arr[i-2]);
        dp[i] = min(one, two);
    }
    return dp[n-1];
}

// Optimise space complexity to constant
int jump3(int n, vector<int>& arr){
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++) {
        int one = prev + abs(arr[i] - arr[i-1]);
        int two = INT_MAX;
        if (i > 1) two = prev2 + abs(arr[i] - arr[i-2]);
        int curr = min(one, two);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

int main() {
    int n;
    cout << "Enter the Number of stairs:\t";
    cin >> n;

    vector<int> height(n);
    cout << "Enter the Elements:\t";
    for (int i = 0; i < n; i++)
        cin >> height[i];

    vector<int> idx(n, -1);
    int result = jump1(n - 1, height, idx);

    cout << "The minimum energy spent is :\t" << result << endl;
    return 0;
}