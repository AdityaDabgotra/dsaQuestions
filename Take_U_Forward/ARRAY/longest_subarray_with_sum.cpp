#include<bits/stdc++.h>
using namespace std;

// BruteForce Approach
int longest_subarray1(vector<int>&arr,int k){
    int length = 0;
    for (int i = 0; i < arr.size(); i++){
        int sum = 0;
        for (int j = i; j < arr.size(); j++){
            sum += arr[j];
            if(sum == k){
                length = max(length,j-i+1);
            }  
        }     
    }
    return length;  
}

// Better Approach for all conditionsS
int longest_subarray2(vector<int>&arr,int k){
    unordered_map<int,int>map;
    int length = 0,sum = 0;
    for(int i = 0;i<arr.size();i++){
        sum += arr[i];
        if(sum == k)length = max(length,i+1);
        if(map.find(sum-k) != map.end()){
            length = max(length,i-map[sum-k]);
        }
        if(map.find(sum) == map.end()){
            map[sum] =i;
        }
    }
    return length;
}

// Best Approach if positive and zero is present
int longest_subarray3(vector<int>& arr, int k) {
    int left = 0, right = 0, sum = 0, largest = 0;

    while (right < arr.size()) {
        sum += arr[right];
        while (sum > k && left <= right) {
            sum -= arr[left];
            left++;
        }
        if (sum == k) {
            largest =max(largest, right - left + 1);
        }
        right++;
    }
    return largest;
}
int main(){
    int size,sum;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    cout<<"Enter the Elements:\t";
    vector<int>array(size);
    for (int i = 0; i < size; i++)
    {
        cin>>array[i];
    }
    cout<<"Enter the target sum:\t";
    cin>>sum;

    cout<<"The longest subarray with "<<sum<<" sum is:\t"<<longest_subarray3(array,sum);
    
    return 0;
}