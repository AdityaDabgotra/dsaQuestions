#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
vector<vector<int>>merge(vector<vector<int>> &interval){
    vector<vector<int>>result;
    sort(interval.begin(),interval.end());
    for (int i = 0; i < interval.size(); i++){
        int start = interval[i][0];
        int end = interval[i][1];
        if(!result.empty() && end <= result.back()[1]) continue;
        for (int j = i+1; j < interval.size(); j++){
            if(interval[j][0] <= end){
                end = max(end,interval[j][1]);
            }
            else break;
        }
        result.push_back({start,end}); 
    }
    return result;
}

// Optimal Approach
vector<vector<int>>merge2(vector<vector<int>> &intervals){
    if (intervals.empty()) return {};
    vector<vector<int>> result;
    sort(intervals.begin(), intervals.end());   
    int left = intervals[0][0], right = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= right) {
            right = max(right, intervals[i][1]);
        } else { 
            result.push_back({left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    result.push_back({left, right});
    return result;
}

int main(){
    int size;
    cout<<"Enter the Size of Intervals:\t";
    cin>>size;

    vector<vector<int>> matrix (size,vector<int>(2));
    cout<<"Enter Elements of Matrix:"<<endl;
    for (int i = 0; i < size; i++){
        for (int j = 0; j < 2; j++){
            cin>>matrix[i][j];
        }
    }
    vector<vector<int>>result = merge2(matrix);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[0].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<"   ";
    }
    
    return 0;
}