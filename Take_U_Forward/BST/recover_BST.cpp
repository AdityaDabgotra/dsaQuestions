#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Bruteforce Approach
void makeBST(TreeNode* root,vector<int>&arr,int &itr){
    if(root == NULL)return;
    makeBST(root->left,arr,itr);
    root->val = arr[itr++];
    makeBST(root->right,arr,itr);
        
}
void insert(TreeNode* root,vector<int>&arr){
    if(root == NULL)return;
    insert(root->left,arr);
    arr.push_back(root->val);
    insert(root->right,arr);
}
void recoverTree1(TreeNode* root) {
    vector<int>in;
    insert(root,in);
    sort(in.begin(),in.end());
    int itr = 0;
    makeBST(root,in,itr);
}

// Optimal Solution
TreeNode* first;
TreeNode* back;
TreeNode* middle;
TreeNode* last;
void inorder1(TreeNode* root){
    if(root == NULL)return;
    inorder1(root->left);
    if(back != NULL && (root->val < back->val)){
        if(first == NULL){
            first = back;
            middle = root;
        }
        else last = root;
    }
    back = root;
    inorder1(root->right);
}
void recoverTree2(TreeNode* root){
    first = middle = last = NULL;
    back = new TreeNode(INT_MIN);
    inorder1(root);
    if(first && last)swap(first->val,last->val);
    else if(first && middle)swap(first->val,middle->val);
}
 
int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(8);
    tree->right = new TreeNode(7);

    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(3);

    recoverTree2(tree);

    return 0;
}