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

bool isLeaf(TreeNode* root){
    if(root->left != NULL || root->right != NULL) return false;
    return true;
}
void addLeftBoundary(TreeNode* root,vector<int>&result){
    TreeNode* curr = root->left;
    while (curr){
        if(!isLeaf(curr))result.push_back(curr->val);
        if(curr->left)curr = curr->left;
        else curr = curr->right;
    } 
}
void addRightBoundary(TreeNode* root,vector<int>&result){
    TreeNode* curr = root->right;
    vector<int>temp;
    while(curr){
        if(!isLeaf(curr))temp.push_back(curr->val);
        if(curr->right)curr = curr->right;
        else curr = curr->left;
    }
    for (int i = temp.size()-1; i >= 0; i--){
        result.push_back(temp[i]);
    }   
}
void addLeaf(TreeNode* root,vector<int> &result){
    if(isLeaf(root)){
        result.push_back(root->val);
    }
    if(root->left)addLeaf(root->left,result);
    if(root->right)addLeaf(root->right,result);

}

vector<int>boundaryTraversal(TreeNode* root){
    vector<int>result;
    if(!root)return result;
    if(!isLeaf(root))result.push_back(root->val);
    addLeftBoundary(root,result);
    addLeaf(root,result);
    addRightBoundary(root,result);
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

    cout<<"Zig Zag Traversal of Tree is:\n";
    vector<int>result = boundaryTraversal(tree);
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}