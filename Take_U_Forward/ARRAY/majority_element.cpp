#include<bits/stdc++.h>
using namespace std;

// Brute Force Approach
int majority1(vector<int> &arr){
    int max_count = 0;
    for (int i = 0; i < arr.size(); i++){
        int count = 0;
        for (int j = 0; j< count; j++){
            if(arr[i] == arr[j])count++;
        }
        max_count = max(max_count,count); 
    }
    return max_count;   
}

// Better Approach
int majority2(vector<int> &arr){
    int max_count = 0;
    unordered_map<int,int>map;
    for(int i = 0;i<arr.size();i++){
        map[arr[i]]++;
    }
    for(auto itr:map){
        max_count = max(max_count,itr.second);
    }
    return max_count;
}

// Optimised Approach by Using Moore's Voting Algorithm
int majority3(vector<int> &arr){
    int ele = INT_MIN;
    int count = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if(count ==0)ele = arr[i];
        if(arr[i] == ele)count++;
        else count--;
    }
    
    int count1 = 0;
    for(int i = 0;i<arr.size();i++){
        if(arr[i] == ele) count1++;
    }

    if(count == 0 || count1 < arr.size()/2 )return -1;
    return ele;  
}

int main(){
    int size;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    cout<<"Enter the Elements:\t";
    vector<int>array(size);
    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
    }
    cout<<"The majority element is :\t"<<majority3(array);
    return 0;
}