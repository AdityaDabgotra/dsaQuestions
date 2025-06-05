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

void ChildrenSum(TreeNode* root){
    if(root == NULL)return ;
    int child = 0;

    if(root->left)child += root->left->val;
    if(root->right)child += root->right->val;

    if(child > root->val)root->val = child;
    else{
        if(root->left)root->left->val= root->val;
        else if(root->right)root->right->val = root->val;
    }
    ChildrenSum(root->left);
    ChildrenSum(root->right);

    int total = 0;
    if(root->left) total += root->left->val;
    if(root->right) total += root->right->val;
    if(root->left || root->right) root->val = total;
}

void preorder(TreeNode* root){
    if(root == NULL)return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    ChildrenSum(tree);
    preorder(tree);
    
    return 0;
}