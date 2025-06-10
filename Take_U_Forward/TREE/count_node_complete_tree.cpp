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
int leftHeight(TreeNode* root){
    if(root == NULL)return 0;
    return leftHeight(root->left)+1;
}
int rightHeight(TreeNode* root){
    if(root == NULL)return 0;
    return rightHeight(root->right)+1;
}
int node(TreeNode* root){
    if(root == NULL)return 0;
    int left =  leftHeight(root);
    int right = rightHeight(root);
    if(left == right){
        return pow(2,left)-1;
    }
    else{
        return 1+ node(root->left) + node(root->right);
    }
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(7);

    int result = node(tree);
    cout<<"The number of Nodes in Binary Tree is:\t"<<result;
    return 0;
}