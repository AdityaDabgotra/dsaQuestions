#include<bits/stdc++.h>
using namespace std;

// Helper Fumciton
bool possible(vector<int>&arr,int painter,int wall){
    int count = 0;
    int total = 0;
    for (int i = 0; i < arr.size(); i++){
        if(total + arr[i] <= wall){
            total += arr[i];
        }
        else{
            count++;
            total = arr[i];
        }
    }
    count++;
    return count <= painter;
}

// Bruteforce Approach
int split1(vector<int>&arr,int painter){
    if(arr.size() < painter)return -1;
    int max_ele = *max_element(arr.begin(),arr.end());
    int sum = accumulate(arr.begin(),arr.end(),0);

    for (int i = max_ele; i <= sum; i++){
        if(possible(arr,painter,i)){
            return i;
        }
    }
    return -1;
}

// Optimised Approach
int split2(vector<int>&arr,int painter){
    if(arr.size() < painter)return -1;
    int left = *max_element(arr.begin(),arr.end());
    int right = accumulate(arr.begin(),arr.end(),0);
    int result = 0;

    while (left <= right){
        int mid = left + (right-left)/2;
        if(possible(arr,painter,mid)){
            result = mid;
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return result;
}

int main(){
    int size,s;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the No of Students:\t";
    cin>>s;
    int result = split2(array,s);
    cout<<"The Min possible pages given to a student is "<<result;
    return 0;
}