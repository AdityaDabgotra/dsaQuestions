#include<bits/stdc++.h>
using namespace std;

// Helper Function
bool canArrange(vector<int>&arr,int c,int dis){
    int last_cow_idx = 0;
    c--;
    for (int i = 1; i < arr.size(); i++){
        if(c == 0)return true;
        if(arr[i]-arr[last_cow_idx] >= dis){
            last_cow_idx = i;
            c--;
        }
    }
    return c == 0;
}

// Bruteforce Approach
int cows1(vector<int>&arr,int c){
    if(c > arr.size())return -1;
    int result = 0;
    sort(arr.begin(),arr.end());
    int end = arr[arr.size()-1]-arr[0];
    for (int i = 1; i <= end; i++){
        if(canArrange(arr,c,i)){
            result = i;
        }
        else{
            break;
        }
    }
    return result;
}

// Optimised Approach
int cows2(vector<int>&arr,int c){
    if(c > arr.size())return -1;
    sort(arr.begin(),arr.end());
    int left = 1;
    int right = arr[arr.size()-1]-arr[0];
    int result = 0;
    while (left <= right){
        int mid = left +(right-left)/2;
        if(canArrange(arr,c,mid)){
            result = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return result;
}
int main(){
    int size,c;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the No of Cows:\t";
    cin>>c;
    int result = cows2(array,c);
    cout<<"The Max Value of Min distance between cows is "<<result;
    return 0;
}