#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int rowMax1(vector<vector<int>>&arr){
    int row = -1;
    int max_count = 0;
    for (int i = 0; i < arr.size(); i++){
        int count = 0;
        for (int j = 0; j < arr[0].size(); j++){
            if(arr[i][j] == 1)count++;
        }
        if(max_count < count){
            max_count = count;
            row = i;
        }
    }
    return row+1;
}

// Optimal Approach
int rowMax2(vector<vector<int>>&arr){
    int row = -1;
    int max_count = 0;
    for (int i = 0; i < arr.size(); i++){
        int left = 0,
        right = arr[0].size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(arr[i][mid] == 1){
                right = mid-1;
            }
            else{
                left = mid+1 ;
            }
        }
        int count = arr[0].size() - left;
        if(max_count < count){
            max_count = count;
            row = i;
        }
    }
    return row+1;
}

int main(){
    int row,cols;
    cout<<"Enter The Size of Row:\t";
    cin>>row;
    cout<<"Enter The Size of Col:\t";
    cin>>cols;
    vector<vector<int>>mat;
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < row; i++){
        for (int j = 0; j < cols; j++){
            cin>>mat[i][j];
        }
    }
    cout<<"The row with max 1 is :\t"<<rowMax2(mat);
    return 0;
}