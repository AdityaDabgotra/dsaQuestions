#include<bits/stdc++.h>
using namespace std;

vector<int>leader1(vector<int>&arr){
    vector<int>result;
    for (int i = 0; i < arr.size(); i++)
    {
        bool flag = false;
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[j]> arr[i]){
                flag = true;
                break;
            }
        }
        if(!flag){
            result.push_back(arr[i]);
        }
    }
    return result;
}

// Optimised Approach
vector<int>leader2(vector<int>&arr){
    vector<int>result;
    int size = arr.size();
    if(size < 1)return result;
    int largest = arr[size-1];
    result.push_back(largest);
    for(int i = size-2;i>=0;i--){
        if(arr[i]> largest){
            result.push_back(arr[i]);
            largest = arr[i];
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
int main(){
    int size;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for(int i = 0; i < size; i++){
        cin>>array[i];
    }
    vector<int>result = leader2(array);
    cout<<"The Leaders in teh Array are:\t";
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}