#include<bits/stdc++.h>
using namespace std;
int median1(vector<vector<int>>&mat){

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
    int result = median1(mat);
    cout<<"The Median of Matrix is :\t"<<result;
    return 0;
}