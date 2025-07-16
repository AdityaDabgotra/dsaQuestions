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

//Using a Bound for Proper BST building 
TreeNode* buildBST(vector<int>& preorder, int& index, int bound) {
    if (index == preorder.size() || preorder[index] > bound) return NULL;
    TreeNode* root = new TreeNode(preorder[index++]);
    root->left = buildBST(preorder, index, root->val);
    root->right = buildBST(preorder, index, bound);
    return root;
}
TreeNode* bstFromPreorder1(vector<int>& preorder) {
    int index = 0;
    return buildBST(preorder, index, INT_MAX);
}

// Sorting Preorder to make inorder and the make a Tree
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder,int& preIndex, int inStart, int inEnd,unordered_map<int, int>& inMap) {
    if (inStart > inEnd) return NULL;

    int rootVal = preorder[preIndex++];
    TreeNode* root = new TreeNode(rootVal);

    int inIndex = inMap[rootVal];

    root->left = buildTree(preorder, inorder, preIndex, inStart, inIndex - 1, inMap);
    root->right = buildTree(preorder, inorder, preIndex, inIndex + 1, inEnd, inMap);

    return root;
}
TreeNode* bstFromPreorder2(vector<int>& preorder) {
    vector<int>inorder = preorder;
    sort(inorder.begin(),inorder.end());
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); ++i) {
        inMap[inorder[i]] = i;
    }

    int preIndex = 0;
    return buildTree(preorder, inorder, preIndex, 0, inorder.size() - 1, inMap);
}


int main(){
    int size;
    cout<<"Enter the Size of Array:\t";
    cin>>size;
    vector<int>arr(size);
    for (int i = 0; i < size; i++){
        cin>>arr[i];
    }
    TreeNode* tree = bstFromPreorder1(arr);
    return 0;
}