#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int count_subarray1(vector<int> &arr,int k){
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr.size(); j++){
            int sum = 0;
            for (int k = i; k <= j; k++){
                sum += arr[k];
            }
            if(sum == k)count++;
        }
    }
    return count;
}

// Better Approach
int count_subarray2(vector<int> &arr,int k){
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        int sum = 0;
        for (int j = i; j < arr.size(); j++){
            sum += arr[j];
            if(sum == k)count++;
        }
    }
    return count;
}

// Optimised Approach
int count_subarray3(vector<int> &arr,int k){
    int count = 0;
    unordered_map<int,int> map;
    int prefix_sum = 0;
    map[0] = 1;
    for (int i = 0; i < arr.size(); i++){
        prefix_sum += arr[i];
        int rem = prefix_sum - k;
        count += map[rem];
        map[prefix_sum]++;
    }
    return count;
}

int main(){
    int size,k;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for(int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the target Sum:\t";
    cin>>k;
    cout<<"The Number of Subarray of sum k are :\t"<<count_subarray3(array,k);
    return 0;
}