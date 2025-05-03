#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
void set1(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(matrix[i][j] == 0){
                for (int k = 0; k < cols; k++){
                    if(matrix[i][k] != 0){
                        matrix[i][k] = -1;
                    }
                }
                for (int k = 0; k < rows; k++){
                    if(matrix[k][j] != 0){
                        matrix[k][j] = -1;
                    }
                }
            }
        }  
    }

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(matrix[i][j] != 1){
                matrix[i][j] = 0;
            }
        }  
    }
    return;
}

// Better Approach
void set2(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<int> rows_arr(rows,0);
    vector<int> cols_arr(cols,0);
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(matrix[i][j] == 0){
                rows_arr[i] = 1;
                cols_arr[j] = 1;
            } 
        }  
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(rows_arr[i] || cols_arr[j]){
                matrix[i][j] = 0;
            }
        }
    }
    return;   
}

// Optimised Approach
void set3(vector<vector<int>> &matrix){
    int rows = matrix.size();
    int cols = matrix[0].size();
    int col0 = 1;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                if(j != 0){
                    matrix[0][j] = 0;
                }
                else{
                    col0 = 0;
                }
            }
        } 
    }
    for (int i = 1; i < rows; i++){
        for (int j = 1; j < cols; j++){
            if(matrix[i][j] != 0){
                if(matrix[0][j] == 0 || matrix[i][0] == 0){
                    matrix[i][j] = 0;
                }
            }
        } 
    }
    if(matrix[0][0] == 0){
        for (int i = 0; i < cols; i++){
            matrix[0][i] = 0;
        } 
    }
    if(col0 == 0){
        for (int i = 0; i < rows; i++){
            matrix[i][0] = 0;
        } 
    }   
    return; 
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
    set3(matrix);
    cout<<"After setting zeroes matrix is :"<<endl;
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            cout<<matrix[i][j]<<" ";
        }    
        cout<<endl;
    }
    return 0;
}