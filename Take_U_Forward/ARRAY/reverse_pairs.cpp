#include<bits/stdc++.h>
using namespace std;

// Bruteforce Appraoch
int count1(vector<int> &arr){
    int size = arr.size();
    int cnt = 0;
    for (int i = 0; i < size; i++){
        for (int j = i+1; j < size; j++){
            if(arr[i]>2*arr[j])cnt++;
        }
    }
    return cnt;
}

// Optimal Approach using merge sort
int merge(vector<int>&arr,int low,int mid,int high){
    int cnt = 0;
    vector<int>temp;
    int left = low;
    int right= mid+1;
    int j = right;

    // Calculate the Number of reverse Pairs
    for (int i = low; i <= mid; i++) {
        while (j <= high && arr[i] > 2LL * arr[j]) {
            j++;
        }
        cnt += (j - (mid + 1));
    }
    
    // merge the sorted left and right part
    while(left <= mid && right <= high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left++]);
        }
        // right is smaller
        else{
            temp.push_back(arr[right++]);
        }
    }
    while(left <= mid){
        temp.push_back(arr[left++]);
    }
    while(right <= high){
        temp.push_back(arr[right++]);
    }

    // transfering merged part back to original part
    for(int i = low;i<=high;i++){
        arr[i] = temp[i-low];
    }
    return cnt;
}
int mergeSort(vector<int> &arr,int low,int high){
    int cnt = 0;
    if(low >= high)return cnt;
    int mid = (low+high)/2;
    cnt += mergeSort(arr,low,mid);
    cnt += mergeSort(arr,mid+1,high);
    cnt += merge(arr,low,mid,high);
    return cnt;
}

int count2(vector<int> &arr){
    int cnt = 0;
    cnt += mergeSort(arr,0,arr.size()-1);
    return cnt;
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
    cout<<"the total Number of Inversions are :\t"<<count2(array);
    return 0;
}