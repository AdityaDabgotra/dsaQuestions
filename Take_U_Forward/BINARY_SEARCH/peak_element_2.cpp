#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
vector<int>peak1(vector<vector<int>>&mat){
    // Return the idx of max Element
    int result = INT_MIN;
    vector<int> ans = {-1,-1};
    for(int i = 0;i<mat.size();i++){
        for(int j = 0;j<mat[0].size();j++){
            if(result < mat[i][j]){
                result = mat[i][j];
                ans = {i,j};
            }
        }
    }
    return ans;    
}

// Optimised Aproach
vector<int>peak2(vector<vector<int>>&mat){
    int left = 0,right = mat[0].size()-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        int max_ele = INT_MIN,max_idx = -1;
        for(int i = 0;i<mat.size();i++){
            if(max_ele < mat[i][mid]){
                max_ele= mat[i][mid];
                max_idx = i;
            }
        }
        bool left_greater = mid == 0 ?false :(mat[max_idx][mid-1] > mat[max_idx][mid]);//should be false
        bool right_greater = mid == mat[0].size()-1 ?false :(mat[max_idx][mid+1] > mat[max_idx][mid]);

        if(!left_greater && !right_greater){
            return {max_idx,mid};
        }
        if(left_greater){
            right = mid-1;
        }
        else left = mid+1;
    }
    return {-1,-1};
}

int main(){
    int row,cols;
    cout<<"Enter The Size of Row:\t";
    cin>>row;
    cout<<"Enter The Size of Col:\t";
    cin>>cols;
    vector<vector<int>>mat(row,vector<int>(cols));
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < cols; j++){
            cin>>mat[i][j];
        }
    }
    vector<int>result = peak1(mat);
    cout<<"The Position of K is :\t"<<result[0]<<" "<<result[1];
    return 0;
}