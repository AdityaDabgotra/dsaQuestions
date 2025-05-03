#include<bits/stdc++.h>
using namespace std;

// Helper Function
bool canEat(vector<int>&arr,int k,int s){
    if(s == 0)return false;
    int time = 0;
    for(int i = 0;i<arr.size();i++){
        time += ceil((double)arr[i]/s);
    }
    return time <= k;
}

// Bruteforce Approach
int koko1(vector<int>&arr,int k){
    int i = 1;
    int max = *max_element(arr.begin(), arr.end());
    while(i<= max){
        if(canEat(arr,k,i)){
            return i;
        }
        i++;
    }
    return -1;
}

// Oprimal Approach
int koko2(vector<int>&arr,int k){
    int left = 1;
    int right = *max_element(arr.begin(), arr.end());
    int result = 1;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(canEat(arr,k,mid)){
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
    cout<<"Enter the total Time KOKO have:\t";
    cin>>k;
    int result = koko2(array,k);
    cout<<"The Minimum Speed of KOKO while eating is "<<result<<" banana /hr";
    return 0;
}