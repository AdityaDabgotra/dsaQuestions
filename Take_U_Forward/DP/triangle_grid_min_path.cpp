#include<bits/stdc++.h>
using namespace std;

// Bruteforce approach using recursion
int cal(vector<vector<int>>&tri,int i,int j){
    if(i >= tri.size() || j >= tri[i].size())return INT_MAX;
    
    int down = cal(tri,i+1,j);
    int down_right = cal(tri,i+1,j+1);
    int best = min(down,down_right);
    
    if(best == INT_MAX)return tri[i][j];
    return tri[i][j] + best;
}
int minimumTotal1(vector<vector<int>>& tri) {
    return cal(tri,0,0);
}

// Optimised solution using memoisation
int find(vector<vector<int>>&tri,vector<vector<int>>&dp,int i,int j){
    if(i >= tri.size() || j >= tri[i].size())return INT_MAX;
    
    if(dp[i][j] != INT_MAX)return dp[i][j];
    if (i == tri.size() - 1) return dp[i][j] = tri[i][j];

    int down = find(tri,dp,i+1,j);
    int down_right = find(tri,dp,i+1,j+1);

    return dp[i][j] = tri[i][j] + min(down,down_right);
}
int minimumTotal2(vector<vector<int>>& tri){
    vector<vector<int>> dp;
    for (int i = 0; i < tri.size(); i++){
        vector<int>temp(i+1,INT_MAX);
        dp.push_back(temp);
    }
    return find(tri,dp,0,0);
}

// Optimised solution using tabulation
int minimumTotal3(vector<vector<int>>tri){
    int n = tri.size();
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < tri[i].size(); j++) {
            tri[i][j] += min(tri[i + 1][j], tri[i + 1][j + 1]);
        }
    }
    return tri[0][0];
}

// Optimised space complexity over tabulation
int minimumTotal4(vector<vector<int>>& tri){
    int n = tri.size();
    vector<int> dp = tri[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < tri[i].size(); j++) {
            dp[j] = tri[i][j] + min(dp[j], dp[j + 1]);
        }
    }
    return dp[0];
}
int main(){
    int height;
    cout<<"Enter the height of triangle:\t";
    cin>>height;
    vector<vector<int>>tri;
    cout<<"Enter the Elements:\n";
    for(int i = 0;i<height;i++){
        vector<int>temp(i+1);
        for (int j = 0; j <i+1;j++){
            cin>>temp[j];
        }
        tri.push_back(temp);
    }
    cout<<"The Min path sum is "<<minimumTotal4(tri);
    return 0; 
}