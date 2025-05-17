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

// Preorder Traversal
void preOrder(TreeNode* root){
    stack<TreeNode*>st;
    st.push(root);
    while (!st.empty()){
        TreeNode* current = st.top();
        st.pop();
        cout << current->val << " ";
        if (current->right) st.push(current->right);
        if (current->left) st.push(current->left);
    }
}

// Inorder Traversal
void inOrder(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* current = root;
    while (current || !st.empty()) {
        while (current) {
            st.push(current);
            current = current->left;
        }
        current = st.top();
        st.pop();
        cout << current->val << " ";
        current = current->right;
    }
}


// Postorder Traversal
void postOrder(TreeNode* root){
    if (!root) return;
    stack<TreeNode*> s1, s2;
    s1.push(root);
    
    while (!s1.empty()) {
        TreeNode* current = s1.top(); s1.pop();
        s2.push(current);

        if (current->left) s1.push(current->left);
        if (current->right) s1.push(current->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->val << " ";
        s2.pop();
    }
}

int main(){
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);
    preOrder(tree);
    cout<<endl;
    inOrder(tree);
    cout<<endl;
    postOrder(tree);
    cout<<endl;
    return 0;
}