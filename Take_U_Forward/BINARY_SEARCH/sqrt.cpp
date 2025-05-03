#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int root1(int n){
    int result = 1;
    if(n < 1)return -1;
    if(n == 1)return 1;
    for (int i = 1; i < n; i++){
        if(i*i <= n){
            result = i;
        }
        else break;
    }
    return result;
}

// Optimed Approach
int root2(int n){
    int left = 1;
    int right = n/2;
    int result;
    while(left <= right){
        int mid = left + (right-left)/2;
        if (mid * mid == n)return mid;
        else if(mid * mid > n){
            right = mid-1;
        }
        else{
            left = mid+1;
            result = mid;
        }
    }
    return result;
}

int main(){
   int num;
   cout<<"Enter the Number :\t";
   cin>>num;
   cout<<"THe Square root of "<<num<<" is "<<root2(num);
   return 0;
}