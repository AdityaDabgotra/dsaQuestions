#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int peak1(vector<int> &arr){
    for(int i = 0;i<arr.size();i++){
        if(i == 0){
            if(arr[i] > arr[i+1])return arr[i];
        }
        else if(i == arr.size()-1){
            if(arr[i] > arr[i-1])return arr[i];
        }
        else{
            if(arr[i] > arr[i-1] || arr[i] > arr[i+1])return arr[i];
        }
    }
    return -1;
}

// Optimised Approach
int peak1(vector<int> &arr){
    int left = 0;
    int right = arr.size()-1;

    while(left<right){
        int mid = left + (right-left)/2;

        // If there is a decreasing curve at left hence peak is at left
        if(arr[mid] < arr[mid-1]){
            right = mid;
        }
        // Otherwise right has the decreasing curve
        else{
            left = mid+1;
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
    int result = peak1(array);
    cout<<"The Peak Element is :\t"<<result;
    return 0;
}