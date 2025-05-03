#include<bits/stdc++.h>
using namespace std;

// Helper Function
bool allocate(vector<int>&arr,int student,int page){
    int count = 1;
    int total = 0;
    for (int i = 0; i < arr.size(); i++){
        if(total + arr[i] > page){
            count++;
            total = arr[i];
        }
        else{
            total += arr[i];
        }
    }
    return count <= student;
}

// Bruteforce Approach
int books1(vector<int>&arr,int student){
    if(student > arr.size())return -1;
    int max_ele = *max_element(arr.begin(),arr.end());
    int sum = accumulate(arr.begin(),arr.end(),0);
    for (int i = max_ele; i <= sum; i++){
        if(allocate(arr,student,i)){
            return i;
        }
    }
    return -1;
}

// Optimised Approach
int books2(vector<int>&arr,int student){
    if(student > arr.size())return -1;
    int left = *max_element(arr.begin(),arr.end());
    int right = accumulate(arr.begin(),arr.end(),0);

    int result = 0;

    while(left <= right){
        int mid = left +(right-left)/2;
        if(allocate(arr,student,mid)){
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
    int size,s;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the No of Students:\t";
    cin>>s;
    int result = books2(array,s);
    cout<<"The Min possible pages given to a student is "<<result;
    return 0;
}