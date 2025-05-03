#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
vector<vector<int>> rotate1(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> result (cols,vector<int>(rows));
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            result[j][rows-1-i] = matrix[i][j];
        }
    }
    return result;
}

// Optimal Approach
vector<vector<int>> rotate2(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; i++){
        for (int j = i+1; j < cols; j++){
            swap(matrix[i][j],matrix[j][i]);
        } 
    }
    for (int i = 0; i <= rows; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }
    return matrix;
}

int main(){
    int rows,cols;
    cout<<"Enter the Number of rows:\t";
    cin>>rows;
    cout<<"Enter the Number of cols:\t";
    cin>>cols;
    vector<vector<int>> matrix (rows,vector<int>(cols));
    cout<<"Enter Elements of Matrix:"<<endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>> result = rotate2(matrix);
    cout<<"After Rotating matrix is:"<<endl;
    for (int i = 0; i < cols; i++){
        for (int j = 0; j < rows; j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}