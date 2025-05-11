#include<bits/stdc++.h>
using namespace std;

// Bruteforce Apprach
vector<int>search1(vector<vector<int>>&mat,int k){
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            if(mat[i][j] == k)return{i,j};
        }
        
    }
    return {-1,-1};
}

// Better Approach
vector<int>search2(vector<vector<int>>&mat,int k){
    for (int i = 0; i < mat.size(); i++){
        if(mat[i][0] < k && mat[i][mat[0].size()-1] > k){
            int left = 0,right = mat[0].size();
            while(left <= right){
                int mid = left + (right-left)/2;
                if(mat[i][mid] == k)return {i,mid};
                else if(mat[i][mid] > k){
                    right = mid-1;
                }
                else{
                    left = mid+1;
                }
            }
        }
    }
    return {-1,-1};
}

// Optimal Approach
vector<int>search3(vector<vector<int>>&mat,int k){
    int r = mat.size()-1,c = mat[0].size()-1;
    int left1 = 0,right1 = r;
    while(left1 <= right1){
        int mid1 = left1 + (right1-left1)/2;
        if(mat[mid1][0] <= k && mat[mid1][c] >= k){
            int left2 = 0,right2 = c;
            while(left2 <= right2){
                int mid2 = left2 + (right2-left2)/2;
                if(mat[mid1][mid2] == k)return {mid1,mid2};
                else if(mat[mid1][mid2] > k)right2 = mid2-1;
                else left2 = mid2+1;
            }
        }
        else if(mat[mid1][0] > k){
            right1 = mid1-1;
        }
        else{
            left1 = mid1+1;
        }
    }
    return {-1,-1};
}

int main(){
    int row,cols,k;
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
    cout<<"Enter the Element to search:\t";
    cin>>k;
    vector<int>result = search3(mat,k);
    cout<<"The Position of K is :\t"<<result[0]<<" "<<result[1];
    return 0;
}