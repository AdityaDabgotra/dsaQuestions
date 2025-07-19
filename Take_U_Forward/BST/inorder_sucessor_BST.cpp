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

// Bruteforce Approach by creating an inorder array
void traversal(TreeNode* root,vector<int>&arr){
    if(root == NULL)return;
    traversal(root->left,arr);
    arr.push_back(root->val);
    traversal(root->right,arr);
}
int sucessor(TreeNode* root,int val){
    vector<int>inorder;
    traversal(root,inorder);
    for (int i = 0; i < inorder.size()-1; i++){
        if(inorder[i] == val)return inorder[i+1];
    }
    return -1;
}

//Optimal Approach
int sucessor(TreeNode* root,int val){
    int suc = -1;
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->val > val){
            suc = curr->val;
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return suc;
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
    cout<<"Enter the Value:\t";
    cin>>val;
    int next = sucessor(tree,val);
    cout<<"The sucessor of "<<val<<" is "<<next;
    return 0;
}