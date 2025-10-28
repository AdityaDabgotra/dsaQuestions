#include<bits/stdc++.h>
using namespace std;

// Using Recursion
int calculate1(int n,vector<int>&nums){
    if (n < 0) return 0;
    if(n == 0)return nums[0];
    int pick = nums[n] + calculate1(n - 2, nums);
    int notpick = calculate1(n - 1, nums);
    return max(pick, notpick);
}

// Using DP
int calculate2(int n,vector<int>&nums,vector<int>&dp){
    if (n < 0) return 0;
    if(n == 0)return nums[0];
    if(dp[n] != 1)return dp[n];
    int pick = nums[n] + calculate2(n - 2, nums,dp);
    int notpick = calculate2(n - 1, nums,dp);
    return dp[n] = max(pick, notpick);
}

// Tabulation
int calculate3(int n, vector<int>& nums) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for (int i = 2; i < n; i++) {
        int take = nums[i] + dp[i - 2];
        int not_take = dp[i - 1];
        dp[i] = max(take, not_take);
    }

    return dp[n - 1];
}

// Space Optimisation
int calculate4(int n, vector<int>& nums) {
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    int prev2 = 0;
    int prev1 = nums[0];

    for (int i = 1; i < n; i++) {
        int take = nums[i] + prev2;
        int not_take = prev1;

        int curr = max(take, not_take);
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}


int main(){
    int size;
    cout<<"Enter the Size of arrya:\t";
    cin>>size;
    vector<int>nums(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>nums[i];
    }
    vector<int>dp(size,-1);
    int result = calculate2(size,nums,dp);
    
    return 0;
}