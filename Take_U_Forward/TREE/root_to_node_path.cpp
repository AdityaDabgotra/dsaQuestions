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

bool find(TreeNode* root,int target,vector<int>&arr){
    if(root == NULL)return false;
    arr.push_back(root->val);
    if(root->val == target){
        return true;
    }
    if (find(root->left, target, arr) || find(root->right, target, arr)) {
        return true;
    }
    arr.pop_back();
    return false;
}
vector<int>rootToNode(TreeNode* root,int target){
    if(root == NULL)return{};
    vector<int>ans;
    find(root,target,ans);
    return ans;
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    int target;
    cout<<"Enter the Target:\t";
    cin>>target;
    vector<int>result = rootToNode(tree,target);
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    
    
    return 0;
}
