#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
vector<int>missing1(vector<int>&arr){
    int miss = -1;
    int rep = -1;
    int sum = 0;
    for (int i = 1; i <= arr.size(); i++){
        int count = 0;
        for (int j = 0; j < arr.size(); j++){
            if(arr[j] == i){
                count++;
            }
        }
        if(count == 2){
            rep = i;
        }
        else if(count == 0){
            miss = i;
        }

        if( miss != -1 && rep != -1)break;
    }
    return{miss,rep};
}

// Better Approach
vector<int>missing2(vector<int>&arr){
    vector<int>temp (arr.size()+1,0);
    int rep = -1;
    int miss = -1;
    for (int i = 0; i < arr.size(); i++){
        if(temp[arr[i]] == 0){
            temp[arr[i]] = arr[i];
        }
        else{
            rep = arr[i];
        }
    }
    for (int i = 1; i < temp.size(); i++){
        if(temp[i]==0)miss = i;
    }
    return {miss,rep};
}

// Optimal Approach using Maths
vector<int> missing3(vector<int>& arr){
    int n = arr.size();
    int sum = 0, sum_sqr = 0;

    int sn = (n * (n + 1)) / 2; // Expected sum of first n natural numbers
    int sn_sqr = (n * (n + 1) * (2 * n + 1)) / 6; // Expected sum of squares

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        sum_sqr += arr[i] * arr[i];
    }

    int diff = sn - sum; // x - y
    int sum_of = (sn_sqr - sum_sqr) / diff; // x + y

    int miss = (diff + sum_of) / 2;
    int rep = sum_of - miss;

    return {miss, rep}; // Returning missing first, then duplicating
}

// Optimal Apprach using Xor Operator
vector<int> missing4(vector<int>& arr) {
    int size = arr.size();
    int xr = 0;
    for (int i = 0; i < size; i++){
        xr ^= arr[i];
        xr ^= i+1;
    }
    int bitNo = 0;
    while (1){
        if((xr & (1<<bitNo)) != 0)break;
        bitNo++;
    }
    int zero = 0;
    int one = 0;
    for (int i = 0; i < size; i++){
        // part of 1 club
        if((arr[i] & (1<<bitNo)) != 0){
            one ^= arr[i];
        }
        // part of 0 club
        else{
            zero ^= arr[i];
        }
        
    }
    for (int i = 1; i <= size; i++){
        // part of 1 club
        if((i & (1<<bitNo)) != 0){
            one ^= i;
        }
        // part of 0 club
        else{
            zero ^= i;
        }  
    }
    int cnt = 0;
    for (int i = 0; i < size; i++){
        if(arr[i] == one)cnt++;
    }
    if(cnt == 2)return {zero,one};
    return {one,zero};
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
    vector<int>result = missing4(array);
    cout<<"The Missing Number is "<<result[0]<<" & Repeating Number is "<<result[1];
    return 0;
}