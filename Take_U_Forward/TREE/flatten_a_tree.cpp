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

TreeNode* back = nullptr;
void flattern(TreeNode* root){
    if(root == NULL)return;
    flattern(root->right);
    flattern(root->left);
    root->right = back;
    root->left = NULL;
    back = root;
}
int main() {
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    flattern(tree);
    while(tree != NULL){
        cout<<tree->val<<" ";
        tree = tree->right;
    }
    cout << endl;

    return 0;
}