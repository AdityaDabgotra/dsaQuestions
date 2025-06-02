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

bool mirror(TreeNode* root1,TreeNode* root2){
    if(root1 == NULL && root2 == NULL)return true;
    else if(root1 == NULL || root2 == NULL)return false;
    return mirror(root1->right,root2->left) && mirror(root1->left,root2->right);
}
bool symmetric(TreeNode* root){
    if(root == NULL)return true;
    return mirror(root->left,root->right);
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    if(symmetric(tree)){
        cout<<"Tree is Symmetric";
    }
    else cout<<"Tree is NOT Symmetric";
    return 0;
}
