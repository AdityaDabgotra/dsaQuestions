#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
int root1(int num,int k){
    if(num<0)return -1;
    if(num == 1)return 1;
    int result = 1;
    for (int i = 2; i <= num; i++){
        if(pow(i,k) <= num){
            result = i;
        }
        else{
            break;
        }
    }
    return result;
}

// Optimal Approach
int power(int mid,int k,int num){
    long long ans = 1;
    for(int i = 1;i<=k;i++){
        ans = ans * mid;
        if(ans > num)return 2;
    }
    if(ans == num)return 1;
    else return 0;
}
int root2(int num,int k){
    int left = 0;
    int right = num/2;
    int result = 1;
    while(left <= right){
        int mid = left + (right-left)/2;
        int pow = power(mid,k,num);
        if(pow == 1)return mid;
        else if(pow == 0){
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    return -1;
}

int main(){
    int num,k;
    cout<<"Enter the Number:\t";
    cin>>num;
    cout<<"Enter the K:\t";
    cin>>k;
    cout<<"The "<<k<<"th root of "<<num<<" is "<<root2(num,k);
    return 0;
}