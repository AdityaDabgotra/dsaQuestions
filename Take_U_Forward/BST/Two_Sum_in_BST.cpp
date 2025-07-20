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
void insert(TreeNode*root,vector<int>&arr){
    if(root == NULL)return;
    insert(root->left,arr);
    arr.push_back(root->val);
    insert(root->right,arr);
}
bool findTarget1(TreeNode* root, int k) {
    vector<int>inorder;
    insert(root,inorder);
    int left = 0;
    int right = inorder.size()-1;
    while(left < right){
        if(inorder[left] + inorder[right] == k)return true;
        else if(inorder[left] + inorder[right] > k){
            right--;
        }
        else{
            left++;
        }
    }
    return false;
}

// Optimal Approach
class BST{
public:
    stack<TreeNode*> stk1;
    stack<TreeNode*> stk2;
    void pushLeft(TreeNode* node) {
        while (node) {
            stk1.push(node);
            node = node->left;
        }
    }
    void pushRight(TreeNode* node) {
        while (node) {
            stk2.push(node);
            node = node->right;
        }
    }
    BST(TreeNode* root){
        pushLeft(root);
        pushRight(root);
    }
    int next() {
        TreeNode* node = stk1.top();
        stk1.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }
    int back() {
        TreeNode* node = stk2.top();
        stk2.pop();
        if (node->left) {
            pushRight(node->left);
        }
        return node->val;
    }
};
bool findTarget2(TreeNode* root,int k){
    if(root == NULL)return false;
    if(root->left == NULL && root->right == NULL)return false;
    BST b1(root);
    int left = b1.next();
    int right = b1.back();
    while(left < right){
        if(left + right == k)return true;
        else if(left + right > k){
            right = b1.back();
        }
        else{
            left = b1.next();
        }
    }
}

int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);

    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);

    int tar;
    cout<<"Enter the Target :\t";
    cin>>tar;
    if(findTarget1(tree,tar))cout<<"The Sum is Present in BST";
    else cout<<"The Sum is NOT Present in BST";

    return 0;
}