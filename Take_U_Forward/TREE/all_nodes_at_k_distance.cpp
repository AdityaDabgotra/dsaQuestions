#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void mark(TreeNode* root,unordered_map<TreeNode*,TreeNode*>&parent){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr->left){
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }   
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*,TreeNode*>parent;
    mark(root,parent);

    unordered_map<TreeNode*,bool>visited;
    queue<TreeNode*>q;
    q.push(target);
    visited[target] = true;

    int curr_level = 0;
    while(!q.empty()){
        int size = q.size();
        if(curr_level++ == k)break;
        for (int i = 0; i < size; i++){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left && !visited[curr->left]){
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if(curr->right && !visited[curr->right]){
                q.push(curr->right);
                visited[curr->right] = true;
            }
            if(parent[curr] && !visited[parent[curr]]){
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
        }
    }
    vector<int>result;
    while (!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        result.push_back(curr->val);
    }
    return result;
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    TreeNode* target = tree->left;

    int k;
    cout<<"Enter K:\t";
    cin>>k;
    vector<int>result = distanceK(tree,target,k);
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    
    return 0;
}