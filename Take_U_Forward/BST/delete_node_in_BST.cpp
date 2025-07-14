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

TreeNode* deleteFromBST(TreeNode* root, int val) {
    if (root == NULL) return NULL;

    if (val < root->val) {
        root->left = deleteFromBST(root->left, val);
    }
    else if (val > root->val) {
        root->right = deleteFromBST(root->right, val);
    }
    else {
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* pred = root->left;
        while (pred->right != NULL) {
            pred = pred->right;
        }
        root->val = pred->val;
        root->left = deleteFromBST(root->left, pred->val);
    }
    return root;
}

int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);

    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);


    int val;
    cout<<"Enter the Value to be deleted:\t";
    cin>>val;
    TreeNode* new_root = deleteFromBST(tree,val);

    return 0;
}