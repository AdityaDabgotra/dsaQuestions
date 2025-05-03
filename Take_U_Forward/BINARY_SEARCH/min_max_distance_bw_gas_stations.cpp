#include<bits/stdc++.h>
using namespace std;

// Bruteforce Arrpoach
long double gasStation1(vector<int>&arr,int station){
    // temp array to store no of gas stations added b/w 2 stations 
    vector<int>howthey(arr.size()-1,0);

    for (int j = 1; j <= station ; j++){
        long double max_val = -1, max_idx = -1;

        // Loop to find the place where to add the gas station
        for (int i = 0; i < arr.size()-1; i++){
            // find diff b/w 2 gas stations 
            int diff = arr[i+1]-arr[i];

            // cal actual distance after placing stations
            int sec_len = diff/(long double)(howthey[i]+1);

            // update the max distance and index
            if(max_val < sec_len){
                max_val = sec_len;
                max_idx = i;
            }
        }
        howthey[max_idx]++;
    }
    long double max_ans = -1;

    for (int i = 0; i < arr.size()-1; i++){
        long double sec_len = (arr[i+1]-arr[i])/(long double)(howthey[i]+1);

        max_ans = max(max_ans,sec_len);
    }
    return max_ans; 
}

// Better Approach using Priority Queue / Heap
long double gasStation2(vector<int>&arr,int station){
    // temp array to store no of gas stations added b/w 2 stations 
    vector<int>howthey(arr.size()-1,0);

    // Priority Queue to store the max distance between stations
    priority_queue<pair<long double ,int>> pq;

    for (int i = 0; i < arr.size()-1; i++){
        pq.push({arr[i+1] - arr[i],i});
    }
    
    for (int j = 1; j <= station ; j++){
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;
        howthey[secInd]++;
        long double iniDiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = iniDiff / (long double) (howthey[secInd+1]);
        pq.push({newSecLen,secInd});
    }
    return pq.top().first;
}

// Helper Function
int cntGasStation(vector<int>& arr, long double dist) {
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        long double segment = (long double)(arr[i] - arr[i - 1]);
        int numBetween = (int)(segment / dist);
        if (segment == numBetween * dist) {
            numBetween--;
        }
        cnt += numBetween;
    }
    return cnt;
}

// Optimised Approach using Binary Search
long double gasStation3(vector<int>& arr, int station) {
    long double left = 0.0;
    long double right = 0.0;

    for (int i = 0; i < arr.size() - 1; i++) {
        right = max(right, (long double)(arr[i + 1] - arr[i]));
    }

    while (right - left > 1e-6) {
        long double mid = left + (right - left) / 2.0;
        int cnt = cntGasStation(arr, mid);

        if (cnt > station) {
            left = mid;
        } else {
            right = mid;
        }
    }

    return right;
}

int main(){
    int size,s;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    cout<<"Enter the No of Gas Stations:\t";
    cin>>s;
    long double result = gasStation3(array,s);
    cout<<"The Min possible distance between two consecutive gas station is "<<result;
    return 0;
}