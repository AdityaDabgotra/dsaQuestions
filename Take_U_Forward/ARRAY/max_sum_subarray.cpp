#include<bits/stdc++.h>
using namespace std;
// Brute Force Approach O(n3)
int max_subarray1(vector<int> &arr){
    int max_sum = 0;
    for (int i = 0; i < arr.size(); i++){
        for(int j = i;j<arr.size();j++){
            int sum = 0;
            for (int k = i; k <=j; k++){
                sum += arr[k];
            }
            max_sum = max(max_sum,sum); 
        }
    }
    return max_sum;
}

// Better Approach  O(n2)
int max_subarray2(vector<int> &arr){
    int max_sum = 0;
    for (int i = 0; i < arr.size(); i++){
        int sum = 0;
        for(int j = i;j<arr.size();j++){
            sum += arr[j];
            max_sum = max(max_sum,sum);
        }
    }
    return max_sum;
}

// Optimal Approach Using Kadane's Algorithm
int max_subarray3(vector<int> &arr){
    int max_sum = 0;
    int sum = 0;
    for (int i = 0; i < arr.size(); i++){
        if(sum < 0) sum = 0;
        sum += arr[i];
        max_sum = max(max_sum,sum);
    }
    return max_sum;
    
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

    cout<<"The maximum Sum subarray is:\t"<<max_subarray3(array);

    return 0;
}