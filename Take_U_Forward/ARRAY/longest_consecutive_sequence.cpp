#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
bool ls(vector<int>&arr,int num){
    for (int i = 0; i < arr.size(); i++){
        if(arr[i] == num)return true;
    }
    return false;
}
int longest1(vector<int> &arr){
    int longest = 1;
    for (int i = 0; i < arr.size(); i++){
        int x = arr[i];
        int curr = 1;
        while (ls(arr,x+1)){
            x++;
            curr++;
        }
        longest = max(longest,curr);  
    }
    return longest;  
}

// Better Approach
int longest2(vector<int> arr){
    if (arr.empty()) return 0;
    sort(arr.begin(), arr.end());
    int last_smaller = arr[0];
    int curr = 1;
    int longest = 1;

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] == arr[i - 1]) continue;
        if (arr[i] == last_smaller + 1) {
            curr++;
            last_smaller = arr[i];
        } else {
            longest = max(longest, curr);
            last_smaller = arr[i];
            curr = 1;
        }
    }
    return max(longest, curr);    
}

// Optimal Approach
int longest3(vector<int>&arr){
    if(arr.size() == 0)return 0;
    unordered_set<int> set;
    int longest = 1;
    for (int i = 0; i < arr.size(); i++){
        set.insert(arr[i]);
    }
    for(auto itr : set){
        if(set.find(itr-1) == set.end()){
            int count = 1;
            int num = itr;
            while(set.find(num+1) != set.end()){
                count++;
                num++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}

int main(){
    int size;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for(int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"The Longest Consecutive Sequence is:\t"<<longest3(array);
    return 0;
}