#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int occurance1(vector<int>&arr,int k){
    int first = -1;
    int last = -1;
    for (int i = 0; i < arr.size(); i++){
        if(arr[i] == k ){
            if(first == -1){
                first = i;
                last = i;
            }
            else{
                last = i;
            }
        }
    }
    return last - first + 1;   
}

// Optimal Appraoch using lower and upper bond concept
int occurance2(vector<int>&arr,int k){
    int first = -1;
    int last = -1;
    int left = 0,right = arr.size()-1;
    while (left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid]==k){
            first = mid;
            right = mid-1;
        }
        else if(arr[mid] > k){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    left = 0,right = arr.size()-1;
    while (left<=right){
        int mid = left + (right-left)/2;
        if(arr[mid]==k){
            last = mid;
            left = mid+1;
        }
        else if(arr[mid] > k){
            right = mid-1;
        }
        else{
            left = mid+1;
        }
    }
    return last - first + 1;   
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
    int result = occurance2(array,k);
    cout<<"The Number of  apperarance of "<<k<<" is "<<result;
    return 0;
}