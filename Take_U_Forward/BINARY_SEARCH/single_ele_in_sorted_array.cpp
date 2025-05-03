#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int single1(vector<int> &arr){
    for (int i = 0; i < arr.size(); i++){
        if(i == 0){
            if(arr[i] != arr[i+1])return arr[i];
        }
        else if(i == arr.size()-1){
            if(arr[i] != arr[i-1])return arr[i];
        }
        else{
            if(arr[i] != arr[i+1] || arr[i] != arr[i+1]) return arr[i];
        }
    }
    return -1;
}

// Bruteforce Approach using Bit Manupulation
int single2(vector<int> &arr){
    int xr = 0;
    for (int i = 0; i < arr.size(); i++){
        xr ^= arr[i];
    }
    return xr;
}

// Optimised Approach using Binary Search
int single3(vector<int> &arr){
    int left = 0;
    int right = arr.size()-1;
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (mid % 2 == 1) mid--;

        if (arr[mid] == arr[mid + 1]) {
            left = mid + 2;
        }
        else {
            right = mid;
        }
    }
    return arr[left];
}

int main(){
    int size;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    int result = single3(array);
    cout<<"The Single Number is :\t"<<result;
    return 0;
}