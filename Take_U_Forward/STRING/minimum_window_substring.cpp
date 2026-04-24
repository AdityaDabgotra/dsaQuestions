#include<bits/stdc++.h>
using namespace std;

// Bruteforce Approach
string minWindow1(string s, string t) {
    // Create all possible substrings and then select the substring which satisfy the t and has
    //min length
}

//Optimized Approach
string minWindow2(string s, string t) {
    unordered_map<char,int>mp;
    for(int i = 0;i<t.size();i++){
        mp[t[i]]++;
    }
    int ansStart = -1;
    int min_len = INT_MAX;

    int start = 0;
    int end = 0;

    int count = 0;
    
    while(end <s.size() || count == t.size()){
        if(count == t.size()){
            if(end-start < min_len){
                ansStart = start;
                min_len = end-start;
            }
            
            mp[s[start]]++;
            if(mp[s[start]] > 0){
                count--;
            }
            start++;
        }
        else{
            if(mp.find(s[end]) != mp.end()){
                if(mp[s[end]] > 0){
                    count++;
                }
                mp[s[end]]--;
            }
            else{
                mp[s[end]] = -1;
            }
            end = end+1;
        }

    }
    if(ansStart == -1) return "";
    return s.substr(ansStart,min_len);
}
int main(){
    string s,t;
    cout<<"Enter S:\t";
    cin>>s;
    cout<<"Enter T:\t";
    cin>>t;
    cout<<minWindow2(s,t);
    return 0;
}