#include <bits/stdc++.h>
using namespace std;

// using normal DP
int jump1(int n, vector<int>& arr, vector<int>& idx,int k) {
    if (n == 0) return 0;

    if (idx[n] != -1) return idx[n];

    int min_weight = INT_MAX;
    for (int i = 1; i <= k; i++){
        if(n - i < 0)break;
        int weight = jump1(n-i,arr,idx,k) + abs(arr[n] - arr[n-i]);
        min_weight = min(weight,min_weight);
    }
    return idx[n] = min_weight;
}

// Using Bottom up DP (Tabulation)
int jump2(int n, vector<int>& arr,int k){
    vector<int> dp(n, 0);
    dp[0] = 0;
    for (int i = 1; i < n; i++){
        int min_weight = INT_MAX;
        for (int j = 1; j <= k; j++){
            if(i-j < 0)break;
            int weight = dp[i-j] + abs(arr[i]-arr[i-j]);
            min_weight = min(weight,min_weight);
        }
        dp[i] = min_weight;
    }
    return dp[n-1];
}

int main() {
    int n;
    cout << "Enter the Number of stairs:\t";
    cin >> n;
    int k;
    cout<<"Enter the maximum Jump it can make:\t";
    cin>>k;
    vector<int> height(n);
    cout << "Enter the Elements:\t";
    for (int i = 0; i < n; i++)
        cin >> height[i];

    vector<int> idx(n, -1);
    
    int result = jump1(n - 1, height, idx,k);

    cout << "The minimum energy spent is :\t" << result << endl;
    return 0;
}