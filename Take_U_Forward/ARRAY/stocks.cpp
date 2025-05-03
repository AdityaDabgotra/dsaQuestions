#include<bits/stdc++.h>
using namespace std;
int sell_stocks(vector<int> &arr){
    int min_price = arr[0];
    int max_profit = 0;
    for (int i = 0; i < arr.size(); i++){
        int profit = arr[i]-min_price;
        max_profit = max(max_profit,profit);
        min_price = min(min_price,arr[i]);
    }
    return max_profit;
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
    cout<<"The Max Profit is :\t"<<sell_stocks(array);
    return 0;
}