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

void insert(TreeNode* root ,vector<int>&v,int k){
    if(root == NULL)return;
    insert(root->left,v,k);
    v.push_back(root->val);
    insert(root->right,v,k);
}
int KthElement(TreeNode* root,int k){
    vector<int>result;
    insert(root,result,k);
    return result[k-1];
    
}

int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);

    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);


    int k;
    cout<<"Enter the Value of K:\t";
    cin>>k;
    int result = KthElement(tree,k);

    return 0;
}