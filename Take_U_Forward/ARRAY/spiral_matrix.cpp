#include<bits/stdc++.h>
using namespace std;

vector<int>spiral(vector<vector<int>> &matrix){
    int left = 0;
    int right = matrix[0].size()-1;
    int top = 0;
    int bottom = matrix.size()-1;
    
    int size = matrix.size()*matrix[0].size();

    vector<int>result;
    int counter = 0;
    while(counter<size){
        for (int i = left; i <= right; i++){
            result.push_back(matrix[top][i]);
            counter++;
        }
        top++;
        for (int i = top; i <= bottom; i++){
            result.push_back(matrix[i][right]);
            counter++;
        }
        right--;
        for (int i = right; i >=left ; i--){
            result.push_back(matrix[bottom][i]);
            counter++;
        }
        bottom--;
        for (int i = bottom; i >=top ; i--){
            result.push_back(matrix[i][left]);
            counter++;
        }
        left++;
    }
    return result;
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

    vector<int>result = spiral(matrix);
    cout<<"The Spiral Matrix is :\t";
    for (int i = 0; i < result.size(); i++)
    {
        cout<<result[i]<<" ";
    }
    
    return 0;
}