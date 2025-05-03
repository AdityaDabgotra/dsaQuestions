#include<bits/stdc++.h>
using namespace std;
// Brute Force Method
vector<int>TwoSum1(vector<int> &arr,int k){
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i+1; j < arr.size(); j++)
        {
            if(arr[i] + arr[j] == k){
                return {i,j};
            }
        }
    }
    return {-1,-1};  
}

// Better Method
vector<int>TwoSum2(vector<int>&arr,int k){
    unordered_map<int,int>map;
    for (int i = 0; i < arr.size(); i++)
    {
        int target = k-arr[i];
        if(map.find(target) != map.end()){
            return {map[target],i};
        }
        map[arr[i]] = i;
    }
    return {-1,-1};   
}

// Optimal Method
vector<int> TwoSum3(vector<int>&arr,int k){
    int left = 0;
    int right = arr.size()-1;
    while(left < right){
        if(arr[left] + arr[right] == k){
            return {left,right};
        }
        else if(arr[left] + arr[right] > k){
            right--;
        }
        else{
            left++;
        }
    }
    return {-1,-1};
}
int main(){
    int size,target;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
    }
    cout<<"Enter The target number:\t";
    cin>>target;
    vector<int>result = TwoSum3(array,target);
    cout<<"The Pair is:\t { "<<result[0]<<" , " <<result[1]<<" }";
    return 0;
}