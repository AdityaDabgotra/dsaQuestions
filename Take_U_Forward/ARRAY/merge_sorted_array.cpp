#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
void merge1(vector<int> &arr1,vector<int> &arr2){
    vector<int>temp;
    int left = 0;
    int right = 0;
    while(left < arr1.size() && right < arr2.size()){
        if(arr1[left] <= arr2[right])temp.push_back(arr1[left++]);
        else temp.push_back(arr2[right++]);
    }
    while(left < arr1.size())temp.push_back(arr1[left++]);
    while(right < arr2.size())temp.push_back(arr2[right++]);
    for (int i = 0; i < arr1.size()+arr2.size(); i++){
        if(i < arr1.size())arr1[i] = temp[i];
        else arr2[i - arr1.size()] = temp[i];
    }
}

// Optimal Approach 1
void merge2(vector<int> &arr1,vector<int> &arr2){
    int left = arr1.size()-1;
    int right = 0;
    while(left >= 0 && right < arr2.size()){
        if(arr1[left] < arr2[right]){
            swap(arr1[left--],arr2[right++]);
        }
        else{
            break;
        }
    }
    sort(arr1.begin(),arr1.end());   
    sort(arr2.begin(),arr2.end());  
}

// Optimal Approach 2 by GAP Method
void merge3(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int gap = (n + m + 1) / 2;  
    
    while (gap > 0) {
        int i = 0, j = gap;
        while (j < n + m) {
            if (i < n && j < n) {
                if (arr1[i] > arr1[j]) {
                    swap(arr1[i], arr1[j]);
                }
            }
            else if (i < n && j >= n) {
                if (arr1[i] > arr2[j - n]) {
                    swap(arr1[i], arr2[j - n]);
                }
            }
            else {
                if (arr2[i - n] > arr2[j - n]) {
                    swap(arr2[i - n], arr2[j - n]);
                }
            }
            i++;
            j++;
        }
        gap = (gap == 1) ? 0 : (gap + 1) / 2;
    }
}
int main(){
    int size1,size2;
    cout<<"Enter the Size of Array 1:\t";
    cin>>size1;
    cout<<"Enter the Elements:\t";

    vector<int>array1(size1);

    for (int i = 0; i < size1; i++){
        cin>>array1[i];
    }
    cout<<"Enter the Size of Array 2:\t";
    cin>>size2;
    cout<<"Enter the Elements:\t";
    vector<int>array2(size2);
    for (int i = 0; i < size2; i++){
        cin>>array2[i];
    }

    merge3(array1,array2);

    cout<<"Elements after Merging of Array 1:\t";
    for (int i = 0; i < size1; i++){
        cout<<array1[i]<<" ";
    }
    cout<<endl;
    cout<<"Elements after Merging of Array 2:\t";
    for (int i = 0; i < size2; i++){
        cout<<array2[i]<<" ";
    }
    return 0;
}