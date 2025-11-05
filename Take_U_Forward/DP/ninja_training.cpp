#include<bits/stdc++.h>
using namespace std;

// Recurssion
int calculate(int n,vector<vector<int>>&arr,int last){
    int maxi = 0;
    if(n == 0){
        for (int i = 0; i < arr[0].size(); i++){
            if(i != last){
                maxi = max(maxi,arr[n][i]);
            }
        }
        return maxi;
    }
    for (int i = 0; i < arr[0].size(); i++){
        if(i != last){
            int result = arr[n][i] + calculate(n-1,arr,i);
            maxi = max(maxi,result);
        }
    }
    return maxi;
}

// Using DP
int calculate2(int n,vector<vector<int>>&arr,int last,vector<vector<int>>&dp){
    int maxi = 0;

    if(dp[n][last] != -1)return dp[n][last];
    if(n == 0){
        for (int i = 0; i < arr[0].size(); i++){
            if(i != last){
                maxi = max(maxi,arr[n][i]);
            }
        }

        return dp[n][last] = maxi;
    }
    
    for (int i = 0; i < arr[0].size(); i++){
        if(i != last){
            int result = arr[n][i] + calculate2(n-1,arr,i,dp);
            
            maxi = max(maxi,result);
        }
    }
    return dp[n][last] = maxi;
}

// Using Bottom Up (Tabulation)
int calculate3(vector<vector<int>>&arr){
    int n = arr.size();
    int m = arr[0].size();

    vector<vector<int>> dp(n, vector<int>(m + 1, 0));

    for (int last = 0; last <= m; last++) {
        int maxi = 0;
        for (int task = 0; task < m; task++) {
            if (task != last)
                maxi = max(maxi, arr[0][task]);
        }
        dp[0][last] = maxi;
    }

    for (int day = 1; day < n; day++) {
        for (int last = 0; last <= m; last++) {
            int maxi = 0;
            for (int task = 0; task < m; task++) {
                if (task != last) {
                    int result = arr[day][task] + dp[day - 1][task];
                    maxi = max(maxi, result);
                }
            }
            dp[day][last] = maxi;
        }
    }
    return dp[n - 1][m];
}


int main(){
    int n,size;
    cout<<"Enter the Number of days:\t";
    cin>>n;
    cout<<"Enter the Size of array:\t";
    cin>>size;
    vector<vector<int>>nums(n,vector<int>(size));

    cout<<"Enter the Elements:\t";
    for (int i = 0; i < n; i++){
        for (int j = 0; j < size; j++){
            cin>>nums[i][j];
        }   
    }
    vector<vector<int>>dp(n,vector<int>(size+1,-1));
    int result = calculate2(n-1,nums,size,dp);
    cout<<"The Maximum points Ninja can score is:\t"<<result;
    
    return 0;
}