#include<bits/stdc++.h>
using namespace std;
vector<int>max_subarray(vector<int> &arr){
    vector<int>result;
    int max_sum = INT_MIN;
    int sum = 0;
    int left =0,right =0;
    for (int i = 0; i < arr.size(); i++){
        if(sum < 0) {
            sum = 0;
            left = i;
        }
        sum += arr[i];
        if(sum > max_sum){
            max_sum = sum;
            right = max(right,i);
        }
    }
    for (int i = left; i <= right; i++)
    {
        result.push_back(arr[i]);
    }
    return result;
}
int main(){
    int size;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    cout<<"Enter the Elements:\t";
    vector<int>array(size);
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    vector<int>result = max_subarray(array);
    cout<<"The maximum Sum subarray is:\t";
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    

    return 0;
}