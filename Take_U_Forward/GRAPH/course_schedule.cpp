#include<bits/stdc++.h>
using namespace std;

bool canFinish(int n, vector<vector<int>>& prere) {
    vector<int>adj[n];
    for(auto it: prere){
        adj[it[0]].push_back(it[1]);
    }
    vector<int> indegree(n, 0);

    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
                
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int count = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }
    return count == n;
}

int main(){
    int numCourses;
    cout<<"Enter the number of Courses:\t";
    cin>>numCourses;
    vector<vector<int>>prerequisites = {{1,0},{2,0},{3,1},{3,2}};
    if(canFinish(numCourses,prerequisites)){
        cout<<"Possible";
    }
    else{
        cout<<"Not Possible";
    }
    return 0;
}