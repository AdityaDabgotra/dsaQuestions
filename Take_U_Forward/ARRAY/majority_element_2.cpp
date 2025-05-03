#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
vector<int>majority1(vector<int> &arr){
    vector<int>result;
    for (int i = 0; i < arr.size(); i++){
        if(result.empty() || (result[0] != arr[i] && result[1] != arr[i])){
            int cnt = 0;
            for (int j = 0; j < arr.size(); j++){
                if(arr[j] == arr[i])cnt++;
            }
            if(cnt > arr.size()/3){
                result.push_back(arr[i]);
            }
        }
        if(arr.size() == 2)break;
    }
    return result;
}

// Better Approach
vector<int>majority2(vector<int> &arr){
    vector<int>result;
    unordered_map<int,int>map;
    for (int i = 0; i < arr.size(); i++){
        map[arr[i]]++;
        if(map[arr[i]] > arr.size()/3){
            result.push_back(arr[i]);
        }
    }
    return result;
}

// Optimal Approach
vector<int>majority3(vector<int> &arr){
    int size = arr.size();
    int cnt1 = 0,cnt2 = 0;
    int ele1 = INT_MIN,ele2 =  INT_MIN;
    for (int i = 0; i < size; i++){
        if(cnt1 == 0 && ele2 != arr[i]){
            ele1 = arr[i];
            cnt1++;
        }
        else if(cnt2 == 0 && ele1 != arr[i]){
            ele2 = arr[i];
            cnt2++;
        }
        else if(arr[i] == ele1) cnt1++;
        else if(arr[i] == ele2) cnt2++;
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0;i<size;i++){
        if(arr[i] == ele1)cnt1++;
        if(arr[i] == ele2)cnt2++;
    }
    if(cnt1 > size/3 && cnt2 > size/3){
        return {ele1,ele2};
    }
    else if(cnt1> size/3){
        return {ele1};
    }
    else{
        return {ele2};
    }
    return{0};
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
    vector<int>result = majority3(array);
    cout<<"The Majority Element greater than n/3 are:\t";
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}