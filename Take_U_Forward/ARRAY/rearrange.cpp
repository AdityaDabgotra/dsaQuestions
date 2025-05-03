#include<bits/stdc++.h>
using namespace std;
vector<int>arrange(vector<int> &arr){
    vector<int>result(arr.size());
    int pos = 0;
    int neg = 1;
    for (int i = 0; i < arr.size(); i++){
        if(arr[i]<0){
            result[neg] = arr[i];
            neg += 2;
        }
        else{
            result[pos] = arr[i];
            pos += 2;
        }
    }
    return result;
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
    vector<int>result = arrange(array);
    cout<<"Array after Arranging is :\t";
    for (int i = 0; i < size; i++){
        cout<<result[i]<<" ";
    }
    return 0;
}