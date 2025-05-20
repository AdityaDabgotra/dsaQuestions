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
int height(TreeNode* root){
    if(root == NULL)return 0;

    int leftSubTree = height(root->left);
    int rightSubTree = height(root->right);

    return max(leftSubTree,rightSubTree)+1;
}
int main(){
    TreeNode* tree = new TreeNode(1);

    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    int result = height(tree);

    cout<<"The Height of Binary Tree is:\t"<<result;
    
    return 0;
}