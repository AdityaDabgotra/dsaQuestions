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

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(root == NULL)return new TreeNode(val);
    TreeNode* curr = root;
    TreeNode* parent = NULL;
    while(curr != NULL){
        if(curr->val > val){
            parent = curr;
            curr = curr->left;
        }
        else{
            parent = curr;
            curr = curr->right;
        }
    }
    if(parent->val > val){
        parent->left = new TreeNode(val);
    }
    else{
        parent->right = new TreeNode(val);
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
    cout<<"Enter the Value to be added:\t";
    cin>>val;
    TreeNode* new_root = insertIntoBST(tree,val);

    return 0;
}