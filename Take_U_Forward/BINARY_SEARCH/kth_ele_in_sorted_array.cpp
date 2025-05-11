#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int merge1(vector<int>&arr1,vector<int>&arr2){
    int s1 = arr1.size();
    int s2 = arr2.size();
    vector<int>result;
    int left = 0,right = 0;
    while(left < s1 && right < s2){
        if(arr1[left] >= arr2[right]){
            result.push_back(arr1[left++]);
        }
        else{
            result.push_back(arr2[right++]);
        }
    }
   while(left < s1){
      result.push_back(arr1[left++]);
   }
   while(right < s2){
      result.push_back(arr2[right++]);
   }
   if(result.size() % 2 != 0){
      return result[(s1+s2)/2];
   }
   else{
      int ans1 = result[(s1+s2)/2];
      int ans2 = result[((s1+s2)/2)-1];
      return (ans1+ans2)/2;
   }
}

// Better Approach
int merge2(vector<int>&arr1,vector<int>&arr2){
   int s1 = arr1.size();
   int s2 = arr2.size();
   int left = 0,right = 0;
   int count = 0;
   int index1= -1,index2 = -1;
   while(left < s1 && right < s2){
      if(arr1[left] <= arr2[right]){
         if(count == (s1+s2)/2)index1 = arr1[left];
         if(count == ((s1+s2)/2)-1)index2 = arr1[left];
         count++;
         left++;
      }
      else{
         if(count == (s1+s2)/2)index1 = arr1[right];
         if(count == ((s1+s2)/2)-1)index2 = arr1[right];
         count++;
         right++;
      }
   }
   while(left < s1){
      if(count == (s1+s2)/2)index1 = arr1[left];
         if(count == ((s1+s2)/2)-1)index2 = arr1[left];
         count++;
         left++;
   }
   while(right < s2){
      if(count == (s1+s2)/2)index1 = arr1[right];
      if(count == ((s1+s2)/2)-1)index2 = arr1[right];
      count++;
      right++;
   }
   if(count % 2 != 0){
      return index1;
   }
   else{
      return (index1+index2)/2;
   }
}

// Optimal Approach
double merge3(vector<int>& arr1, vector<int>& arr2,int k) {
    int s1 = arr1.size();
    int s2 = arr2.size();

    if (s1 > s2) return merge3(arr2, arr1,k);

    int low = max(0,k-s2), high = min(s1,k);
    int Left = k;

    while (low <= high) {
        int mid1 = (low+high)>>1;
        int mid2 = Left - mid1;

        int l1 = INT_MIN,l2 = INT_MIN;
        int r1 = INT_MAX,r2 = INT_MAX;

        if(mid1 < s1)r1 = arr1[mid1];
        if(mid2 < s2)r2 = arr2[mid2];

        if(mid1-1 >=0) l1 = arr1[mid1-1];
        if(mid2-1 >=0) l2 = arr2[mid2-1];

        if (l1 <= r2 && l2 <= r1) {
            return max(l1,l2);
        }
        else if (l1 > r2) {
            high = mid1 - 1;
        }
        else {
            low = mid1 + 1;
        }
    }
    return 0;
}


int main(){
    int size1,size2,k;
    cout<<"Enter the Size of Array 1:\t";
    cin>>size1;
    vector<int>array1(size1);
    cout<<"Enter your Elements:\t";
    for (int i = 0; i < size1; i++){
        cin>>array1[i];
    }

    cout<<"Enter the Size of Array 2:\t";
    cin>>size2;
    vector<int>array2(size2);
    cout<<"Enter your Elements:\t";
    for (int i = 0; i < size2; i++){
        cin>>array2[i];
    }
    cout<<"Enter the K:\t";
    cin>>k;
    cout<<"The Kth Element of the two sorted array is:\t"<<merge3(array1,array2,k);
    return 0;
}