#include<bits/stdc++.h>
using namespace std;

// Helper Function
bool makeBouque(vector<int>&arr,int m, int k,int num){
    int counter = 0;
    int bou = 0;
    for (int i = 0; i < arr.size(); i++){
        if(arr[i] <= num){
            counter++;
        }
        else{
            bou += counter/k;
            counter = 0;
        }
    }
    bou += counter/k;
    return bou >= m;
}

// Bruteforce Approach
int bouque1(vector<int> &arr,int m,int k){
    if(m*k > arr.size())return -1;
    
    int max_ele = *max_element(arr.begin(),arr.end());
    int min_ele = *min_element(arr.begin(),arr.end());

    for (int i = min_ele; i <= max_ele; i++){
        if(makeBouque(arr,m,k,i)){
            return i;
        }
    }
    return -1;
}

// Optimised Approach
int bouque2(vector<int> &arr,int m,int k){
    if(m*k > arr.size())return -1;
    
    int left = *min_element(arr.begin(),arr.end());
    int right = *max_element(arr.begin(),arr.end());

    int result = right;
    while(left <= right){
        int mid = left + (right-left)/2;
        if(makeBouque(arr,m,k,mid)){
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
    int size,m,k;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the number of Bouque:\t";
    cin>>m;
    cout<<"Enter the No of flowers in a single bouque:\t";
    cin>>k;
    int result = bouque2(array,m,k);
    cout<<"The Minimum no of days required are "<<result;
    return 0;
}