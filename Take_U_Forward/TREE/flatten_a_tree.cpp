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

// Using Recursion
TreeNode* back = nullptr;
void flattern1(TreeNode* root){
    if(root == NULL)return;
    flattern1(root->right);
    flattern1(root->left);
    root->right = back;
    root->left = NULL;
    back = root;
}

// Using Stack
void flattern2(TreeNode* root){
    stack<TreeNode*>st;
    st.push(root);
    while(!st.empty()){
        TreeNode* curr = st.top();
        st.pop();
        if(curr->right)st.push(curr->right);
        if(curr->left)st.push(curr->left);

        if(!st.empty())curr->right = st.top();
        curr->left = NULL;
    }
}

// Using Morris Traversal
void flattern3(TreeNode* root){
    TreeNode* curr = root;
    while(curr != NULL){
        if(curr->left != NULL){
            TreeNode* prev = curr->left;
            while(prev->right){
                prev = prev->right;
            }
            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
int main() {
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    flattern1(tree);
    while(tree != NULL){
        cout<<tree->val<<" ";
        tree = tree->right;
    }
    cout << endl;

    return 0;
}