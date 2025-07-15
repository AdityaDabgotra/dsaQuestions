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

bool isValidBST(TreeNode* root) {
    return validate(root, LONG_MIN, LONG_MAX);
}

bool validate(TreeNode* node, long minVal, long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
}

int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);

    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);

    bool result = isValidBST(tree);

    if(result)cout<<"Tree is BST";
    else cout<<"Tree is not BST";

    return 0;
}