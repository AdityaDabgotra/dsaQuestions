#include<bits/stdc++.h>
using namespace std;

// BruteForce Approach
vector<int> next_permutation1(vector<int> &arr){
    // Generate all permutations in ascending order
    // linearly search for the input array and give the next array as output
    //if last array is given return the first array
}

// Better Approach using in Build STL
vector<int> next_permutation2(vector<int> &arr){
    next_permutation(arr.begin(),arr.end());
    return arr;
}

// Optimal Approach
vector<int> next_permutation3(vector<int> &arr){
    int size = arr.size();
    int index = -1;
    for (int i = size-2; i >= 0; i--){
        if(arr[i] < arr[i+1]){
            index= i;
            break;
        }
    }
    if(index == -1){
        reverse(arr.begin(),arr.end());
        return arr;
    }
    int min_idx = size - 1;
    for (int i = size - 1; i > index; i--) {
        if (arr[i] > arr[index]) {
            min_idx = i;
            break;
        }
    }
    swap(arr[index++],arr[min_idx]);
    reverse(arr.begin()+index,arr.end());
    return arr;
    
}
int main(){
    int size;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>array(size);
    cout<<"Enter the Elements:\t";
    for (int i = 0; i < size; i++){
        cin>>array[i];
    }
    vector<int> result = next_permutation3(array);
    cout<<"The next Permutation is :\t";
    for (int i = 0; i < size; i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}