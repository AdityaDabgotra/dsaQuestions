#include<bits/stdc++.h>
using namespace std;

// Bruteforce Appraoch
bool search1(vector<int>&arr,int k){
    for (int i = 0; i < arr.size(); i++){
        if(arr[i] == k)return true;
    }
    return false;
}

// Optimised Appraoch
bool search2(vector<int>&arr,int k){
    int left = 0;
    int right = arr.size()-1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(arr[mid] == k)return true;
        else if(arr[left] == arr[mid] && arr[mid] == arr[right]){
            left++;
            right--;
        }
        // find the sorted side
        else if(arr[left] <= arr[mid]){
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
    return false;
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
    if(search2(array,k)){
        cout<<k<<" is present in the array";
    }
    else{
        cout<<k<<" is not present in the array";
    }
    return 0;
}