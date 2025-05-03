#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int xor_subarray1(vector<int> &arr,int sum){
    int count = 0;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i; j < arr.size(); j++){
            int temp = arr[i];
            for (int k = i+1; k <= j; k++){
               temp ^= arr[k];
            }
            if(temp == sum)count++;
        } 
    }
    return count;
}

// Better Approach
int xor_subarray2(vector<int> &arr, int sum) {
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        int temp = arr[i]; 
        if (temp == sum) count++; 
        for (int j = i + 1; j < arr.size(); j++) { 
            temp ^= arr[j];
            if (temp == sum) count++;  
        }
    }
    return count;
}

// Optimal Approach
int xor_subarray3(vector<int> &arr, int sum) {
    int count = 0;
    unordered_map<int,int> map;
    int temp = 0;
    map[temp]++;
    for (int i = 0; i < arr.size(); i++) {
        temp ^= arr[i];
        int xr = temp ^ sum;
        count += map[xr];
        map[temp]++;
    }
    return count;
}

int main(){
    int size,sum;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for(int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the Sum of Xor:\t";
    cin>>sum;
    cout<<"the number of subarray with sum "<<sum<<" is:\t"<<xor_subarray3(array,sum);
    return 0;
}