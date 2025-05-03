#include<bits/stdc++.h>
using namespace std;
// Brute Force Method
vector<int>arrange1(vector<int>&arr){
    sort(arr.begin(),arr.end());
    return arr;
}

// Moderate Approach
vector<int>arrange2(vector<int>&arr){
    vector<int>result;
    int a=0,b=0,c=0;
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 0)a++;
        if(arr[i] == 1)b++;
        if(arr[i] == 2)c++;
    }
    while(a--){
        result.push_back(0);
    }
    while(b--){
        result.push_back(1);
    }
    while(c--){
        result.push_back(2);
    }
    return result;
}

// Optimal Approach Using 'Dutch National Flag Algorithm'
vector<int> arrange3(vector<int>&arr){
    int low = 0,mid = 0,high = arr.size()-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[mid++],arr[low++]);
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid],arr[high--]);
        }
    }
    return arr;
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
    vector<int>result = arrange3(array);
    cout<<"After Arranging the Array is:\t";
    for (int i = 0; i < size; i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}