#include<bits/stdc++.h>
using namespace std;

// Brutrforce Approach
int median1(vector<vector<int>>&mat){
    vector<int>result;
    for (int i = 0; i < mat.size(); i++){
        for (int j = 0; j < mat[0].size(); j++){
            result.push_back(mat[i][j]);
        } 
    }
    sort(result.begin(),result.end());
    int size = result.size();
    return result[size/2];
}

// Helper Function
int occu(vector<vector<int>>&mat,int num){
    int counter = 0;
    for (int i = 0; i < mat.size(); i++){
        int left = 0,right = mat[0].size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(mat[i][mid] <= num)left = mid+1;
            else right = mid-1;
        }
        counter += left;
    }
    return counter;
}
// Optimised Approach
int median2(vector<vector<int>>&mat){
    int r=mat.size(),c=mat[0].size();
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < mat.size(); i++){
        low = min(low,mat[i][0]);
        high = max(high,mat[i][mat[0].size()-1]);
    }
    while(low <= high){
        int mid= low+ (high-low)/2;
        int smallerEqual = occu(mat,mid);
        if(smallerEqual <= (r*c)/2){
            low = mid+1;
        }
        else high = mid-1;
    }
    return low;
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
    int result = median2(mat);
    cout<<"The Median of Matrix is :\t"<<result;
    return 0;
}