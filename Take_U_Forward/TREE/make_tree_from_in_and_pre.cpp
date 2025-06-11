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
TreeNode* buildTree(vector<int>&preorder,vector<int>&inorder){
    if (preorder.empty() || inorder.empty()) return nullptr;

    TreeNode* root = new TreeNode(preorder[0]);

    int i = 0;
    while (i < inorder.size() && inorder[i] != preorder[0]) i++;

    // Inorder
    vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
    vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());

    // Preorder
    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + i);
    vector<int> rightPreorder(preorder.begin() + 1 + i, preorder.end());

    root->left = buildTree(leftPreorder, leftInorder);
    root->right = buildTree(rightPreorder, rightInorder);

    return root;
}

int main() {
    int size;
    cout<<"Enter the Size of Tree:\t";
    cin>>size;
    cout<<"Enter the preOrder Array:\n";
    vector<int>preorder(size);
    for (int i = 0; i < size; i++){
        cin>>preorder[i];
    }
    cout<<"\nEnter the Inorder Array:\n";
    vector<int>inorder;
    for (int i = 0; i < size; i++){
        cin>>inorder[i];
    }
    TreeNode* tree = buildTree(preorder,inorder);
    return 0;
}