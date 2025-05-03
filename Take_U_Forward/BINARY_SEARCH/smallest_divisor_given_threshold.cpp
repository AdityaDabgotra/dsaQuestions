#include<bits/stdc++.h>
using namespace std;

// Helper Function
bool possible(vector<int>&arr,int k,int div){
    int temp = 0;
    for (int i = 0; i < arr.size(); i++){
        temp += ceil((double)arr[i]/div);
    }
    return temp <= k;
    
}

// Bruteforce Appoach
int divisor1(vector<int>&arr,int k){
    int max_ele = *max_element(arr.begin(),arr.end());

    for (int i = 1; i <= max_ele; i++){
        if(possible(arr,k,i)){
            return i;
        }
    }
    return -1;
}

// Optimised Approach
int divisor2(vector<int>&arr,int k){
    int left = 1;
    int right = *max_element(arr.begin(),arr.end());
    int result = right;

    while(left <= right){
        int mid = left + (right-left)/2;
        if(possible(arr,k,mid)){
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
    int size,k;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the Threshold:\t";
    cin>>k;
    int result = divisor2(array,k);
    cout<<"The Smallest Divisor within the Threahold is "<<result;
    return 0;
}