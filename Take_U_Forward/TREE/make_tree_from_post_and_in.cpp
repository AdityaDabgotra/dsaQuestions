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
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) return nullptr;

    int rootVal = postorder.back();
    TreeNode* root = new TreeNode(rootVal);

    int i = 0;
    while (i < inorder.size() && inorder[i] != rootVal) i++;

    vector<int> leftInorder(inorder.begin(), inorder.begin() + i);
    vector<int> rightInorder(inorder.begin() + i + 1, inorder.end());

    vector<int> leftPostorder(postorder.begin(), postorder.begin() + i);
    vector<int> rightPostorder(postorder.begin() + i, postorder.end() - 1);

    root->left = buildTree(leftInorder, leftPostorder);
    root->right = buildTree(rightInorder, rightPostorder);

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