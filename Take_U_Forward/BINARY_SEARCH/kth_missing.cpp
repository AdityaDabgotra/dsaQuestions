#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int missing1(vector<int>&arr,int k){
    for (int i = 0; i < arr.size(); i++){
        if(k >= arr[i])k++;
        else break;
    }
    return k;
}

// Optimised Approach
int missing2(vector<int>&arr,int k){
    int left = 0;
    int right = arr.size()-1;

    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid]-mid-1 < k){
            left = mid + 1;
        }
        else{
            right = mid-1;
        }
    }
    return right + k + 1;
}

int main(){
    int size,k;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the K:\t";
    cin>>k;
    int result = missing2(array,k);
    cout<<"The "<<k<<"th missing number is "<<result;
    return 0;
}