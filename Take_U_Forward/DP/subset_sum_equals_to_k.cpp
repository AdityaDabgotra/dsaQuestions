#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach using recursion
bool subset_sum(vector<int>&arr,int idx,int tar){
    if(tar < 0)return false;
    if(tar == 0)return true;
    if(idx < 0)return false;

    bool include = subset_sum(arr,idx-1,tar-arr[idx]);
    bool exclude = subset_sum(arr,idx-1,tar);
    return include || exclude;
}

// improved approach using memoisation
bool cal(vector<int>&arr,int idx,int tar,vector<vector<int>>&dp){
    if(tar < 0)return false;
    if(tar == 0)return true;
    if(idx < 0)return false;

    if(dp[idx][tar] != -1){
        return dp[idx][tar] == 1;
    }

    bool include = cal(arr,idx-1,tar-arr[idx],dp);
    bool exclude = cal(arr,idx-1,tar,dp);
    bool result = include || exclude;

    if(result){
        dp[idx][tar] = 1;
    }
    else{
        dp[idx][tar] = 0;
    }
    return result;
}
bool subset_sum2(vector<int>&arr,int idx,int tar){
    int size = arr.size();
    vector<vector<int>>dp(size,vector<int>(tar+1,-1));
    return cal(arr,idx,tar,dp);
}

// Optimized approach using tabulation
bool subset_sum3(vector<int>& arr, int tar) {
    int size = arr.size();
    vector<vector<bool>> dp(size, vector<bool>(tar + 1, false));
    
    for (int i = 0; i < size; i++) dp[i][0] = true;

    if (arr[0] <= tar) dp[0][arr[0]] = true;

    for (int index = 1; index < size; index++) {
        for (int target = 1; target <= tar; target++) {
            bool notTake = dp[index - 1][target];

            bool take = false;
            if (arr[index] <= target)
                take = dp[index - 1][target - arr[index]];

            dp[index][target] = take || notTake;
        }
    }
    return dp[size - 1][tar];
}

// Space optimized solution
bool subset_sum4(vector<int>& arr, int tar) {
    int size = arr.size();

    vector<bool> prev(tar + 1, false);
    vector<bool> curr(tar + 1, false);

    prev[0] = true;

    if (arr[0] <= tar)
        prev[arr[0]] = true;

    for (int index = 1; index < size; index++) {
        fill(curr.begin(), curr.end(), false);
        curr[0] = true;

        for (int target = 1; target <= tar; target++) {

            bool notTake = prev[target];

            bool take = false;
            if (arr[index] <= target)
                take = prev[target - arr[index]];

            curr[target] = take || notTake;
        }

        prev = curr;
    }

    return prev[tar];
}

int main(){
    int size,k;
    cout<<"Enter the size of array:\t";
    cin>>size;
    cout<<"Enter the elements:\t";
    vector<int>arr(size);
    for (int i = 0; i < size; i++){
        cin>>arr[i];
    }
    cout<<"Enter the target sum:\t";
    cin>>k;
    if(subset_sum4(arr,k)){
        cout<<"It is possible";
    }
    else{
        cout<<"It is NOT possible";
    }

    return 0;
}