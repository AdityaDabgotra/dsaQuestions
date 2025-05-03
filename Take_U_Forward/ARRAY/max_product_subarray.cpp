#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int max_subarray1(vector<int>&arr){
    int max_prod = INT_MIN;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr.size(); j++){
            int prod = 1;
            for (int k = i; k <= j; k++){
                prod *= arr[k];
            }
            max_prod = max(max_prod,prod);
        }  
    }
    return max_prod;
}

// Better Approach
int max_subarray2(vector<int>&arr){
    int max_prod = INT_MIN;
    for (int i = 0; i < arr.size(); i++){
        int prod = 1;
        for (int j = i; j < arr.size(); j++){
            prod *= arr[j];
            max_prod = max(max_prod,prod);
        }  
    }
    return max_prod;
}

// Optimal Approach
int max_subarray3(vector<int>&arr){
    int max_prod = INT_MIN;
    int prefix = 1;
    int suffix = 1;
    for(int i = 0;i<arr.size();i++){
        if(prefix == 0)prefix = 1;
        if(suffix == 0)suffix = 1;
        prefix *= arr[i];
        max_prod = max(max_prod,prefix);
        suffix *= arr[arr.size()-i-1];
        max_prod = max(max_prod,suffix);
    }
    return max_prod;
}

int main(){
    int size;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    cout<<"Enter the Elements:\t";
    vector<int>array(size);
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"The maximum Product subarray is:\t"<<max_subarray3(array);
    return 0;
}