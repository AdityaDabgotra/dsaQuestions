#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int minimum1(vector<int>&arr){
    int min_ele = INT_MAX;
    for (int i = 0; i < arr.size(); i++){
        min_ele = min(min_ele,arr[i]);
    }
    return min_ele;  
}

// Optimied Approach
int minimum2(vector<int>&arr){
    int left = 0;
    int right = arr.size()-1;
    while (left < right){
        int mid = left + (right-left)/2;

        if(arr[mid] > arr[right]){
            left = mid+1;
        }
        else{
            right = mid;
        }
    }
    return arr[left];   
}

// Optimised Approach 2
int minimum3(vector<int>&arr){
    int left = 0;
    int right = arr.size()-1;
    int min_ele = INT_MAX;
    while (left <= right){
        // if the whole search space is sorted
        if(arr[left] <= arr[right]){
            min_ele = min(arr[left],min_ele);
            break;
        }
        int mid = left + (right-left)/2;
        if(arr[left]< arr[mid]){
            min_ele = min(arr[left],min_ele);
            left = mid+1;
        }
        else{
            min_ele = min(min_ele,arr[mid]);
            right = mid-1;
        }
    }
    return min_ele;   
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
    int result = minimum3(array);
    cout<<"The Minimum Element is "<<result;
    return 0;
}