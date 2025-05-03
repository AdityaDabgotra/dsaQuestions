#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int rotated1(vector<int>&arr){
    int min_idx = arr.size();
    int min_ele = INT_MAX;
    for (int i = 0; i < arr.size(); i++){
        if(arr[i]<min_ele){
            min_idx = min(min_idx,i);
        }
    }
    return min_idx;  
}

// Optimied Approach
int rotated2(vector<int>&arr){
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
    return left;   
}

// Optimised Approach 2
int rotated3(vector<int>&arr){
    int left = 0;
    int right = arr.size()-1;
    int min_ele = INT_MAX;
    int min_idx = arr.size();
    while (left <= right){
        // if the whole search space is sorted
        if(arr[left] <= arr[right]){
            if(arr[left] < min_ele){
                min_ele = min_ele;
                min_idx = left;
                break;
            }
        }
        int mid = left + (right-left)/2;
        if(arr[left]< arr[mid]){
            if(arr[left] < min_ele){
                min_ele = min_ele;
                min_idx = left;
            }
            left = mid+1;
        }
        else{
            if(arr[mid] < min_ele){
                min_ele = arr[mid];
                min_idx = mid;
                break;
            }
            right = mid-1;
        }
    }
    return min_idx;   
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
    int result = rotated3(array);
    cout<<"The Number of times the array is rotated :\t"<<result;
    return 0;
}