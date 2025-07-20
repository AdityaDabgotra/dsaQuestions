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

class BSTIterator {
public:
    stack<TreeNode*> stk;
    void pushLeft(TreeNode* node) {
        while (node) {
            stk.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    bool hasNext() {
        return !stk.empty();
    }
    int next() {
        TreeNode* node = stk.top();
        stk.pop();
        if (node->right) {
            pushLeft(node->right);
        }
        return node->val;
    }
};

int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);

    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);

    return 0;
}