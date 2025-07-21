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

// Bruteforce Approach
int count(TreeNode* root) {
    if (!root) return 0;
    return 1 + count(root->left) + count(root->right);
}
bool validate(TreeNode* node, long minVal, long maxVal) {
    if (!node) return true;
    if (node->val <= minVal || node->val >= maxVal) return false;
    return validate(node->left, minVal, node->val) && validate(node->right, node->val, maxVal);
}

TreeNode* largest1(TreeNode* root) {
    if (!root) return nullptr;
    if (validate(root, LONG_MIN, LONG_MAX)) {
        return root;
    }
    TreeNode* l = largest1(root->left);
    TreeNode* r = largest1(root->right);
    int leftSize = count(l);
    int rightSize = count(r);
    return leftSize >= rightSize ? l : r;
}

// Optimised Approach
pair<pair<int, int>, int> pass(TreeNode* root) {
    if (root == NULL) {
        return { {INT_MAX, INT_MIN}, 0 };
    }

    auto leftTree = pass(root->left);
    auto rightTree = pass(root->right);

    if (leftTree.first.second < root->val && root->val < rightTree.first.first) {
        int subtreeMin = root->left ? leftTree.first.first : root->val;
        int subtreeMax = root->right ? rightTree.first.second : root->val;
        int subtreeSize = leftTree.second + rightTree.second + 1;
        return { {subtreeMin, subtreeMax}, subtreeSize };
    } else {
        return { {INT_MIN, INT_MAX}, max(leftTree.second, rightTree.second) };
    }
}

int largest2(TreeNode* root) {
    return pass(root).second;
}


int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);

    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);

    int result = largest2(tree);


    return 0;
}