#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
vector<vector<int>> sum1(vector<int>&arr){
    vector<vector<int>>result;
    for (int i = 0; i < arr.size(); i++){
        for (int j = i+1; j < arr.size(); j++){
            for (int k = j+1; k < arr.size(); k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    result.push_back({arr[i],arr[j],arr[k]});
                }
            } 
        }
    }
    return result;
}

//BetterApproach
vector<vector<int>> sum2(vector<int>& arr) {
    set<vector<int>>st;
    for (int i = 0; i < arr.size(); i++) {
        unordered_set<int> hash;
        for (int j = i + 1; j < arr.size(); j++) {
            int target = -(arr[i] + arr[j]); 
            if (hash.find(target) != hash.end()) {
                vector<int> temp = {arr[i], arr[j], target};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hash.insert(arr[j]);
        }
    }
    vector<vector<int>> result(st.begin(), st.end());
    return result;
}

// Optimal Approach
vector<vector<int>> sum3(vector<int>&arr){
    sort(arr.begin(),arr.end());
    vector<vector<int>>result;
    for (int i = 0; i < arr.size(); i++){
        if(i > 0 && arr[i] == arr[i-1])continue;
        int j = i+1;
        int k = arr.size()-1;
        while (k > j){
            if(arr[i] + arr[j] + arr[k] == 0){
                result.push_back({arr[i],arr[j],arr[k]});
                while(j< k && arr[k] == arr[k-1]){
                    k--;
                }
                while(j<k && arr[j] == arr[j+1]){
                    j++;
                }
                k--;
                j++;
            }
            else if(arr[i]+arr[j]+arr[k] > 0){
                k--;
            }
            else{
                j++;
            }
        }
        
    }
    return result;
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
    cout<<"The three Sum possible are:\t";
    vector<vector<int>>result = sum3(array);
    for (int i = 0; i < result.size(); i++){
        cout<<" {"<<result[i][0]<<" , "<<result[i][1]<<" , "<<result[i][2]<<" } ";
    }
    return 0;
}