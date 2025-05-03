#include<bits/stdc++.h>
using namespace std;

// Helper Function
bool possible(vector<int>&arr,int days,int cap){
    int temp = 0;
    int time = 0;
    for (int i = 0; i < arr.size(); i++){
        if(temp + arr[i] > cap){
            time++;
            temp = arr[i];
        }
        else{
            temp += arr[i];
        }
    }
    if(temp > 0)time++;
    return time <= days;
}

// Bruteforce Approach
int weight1(vector<int>&arr,int days){
    int max_cap = 1;
    for (int i = 0; i < arr.size(); i++){
        max_cap += arr[i];
    }
    
    for (int i = 1; i <= max_cap; i++){
        if(possible(arr,days,i)){
            return i;
        }
    }
    return -1;
}

// Optimised Approach
int weight2(vector<int>&arr,int days){
    int left = 1;
    int right = 1;
    for (int i = 0; i < arr.size(); i++){
        right += arr[i];
    }
    int result = right;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(possible(arr,days,mid)){
            result = mid;
            right = mid-1;
        }
        else{
            left = mid +1;
        }
    }
    
    return result;
}

int main(){
    int size,days;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the total days we have:\t";
    cin>>days;
    int result = weight2(array,days);
    cout<<"The Minimum Weight Capacity of the Ship is "<<result;
    return 0;
}