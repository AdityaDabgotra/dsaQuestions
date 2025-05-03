#include<bits/stdc++.h>
using namespace std;

// Bruteforce Appraoch
int search1(vector<int>&arr,int k){
    for (int i = 0; i < arr.size(); i++){
        if(arr[i] == k)return i;
    }
    return -1;
}

// Optimised Appraoch
int search2(vector<int>&arr,int k){
    int left = 0;
    int right = arr.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == k)return mid;
        // find the sorted side
        if(arr[left] <= arr[mid]){
            // left side is sorted
            if(arr[left] <= k && arr[mid] > k){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        else{
            // right side is sorted
            if(arr[mid] < k && arr[right] >= k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
    }
    return -1;
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
    cout<<"Enter the Target Number:\t";
    cin>>k;
    cout<<"The position of "<<k<<" is "<<search2(array,k);
    return 0;
}