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

vector<int> inorder(TreeNode* root) {
    vector<int> result;
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            result.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                result.push_back(curr->val);
                curr = curr->right;
            }
        }
    }
    return result;
}
vector<int> preorder(TreeNode* root){
    vector<int> result;
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            result.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;
            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = curr;
                result.push_back(curr->val);
                curr = curr->left;
            } else {
                prev->right = NULL;
                curr = curr->right;
            }
        }
    }
    return result;
}

int main() {
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    vector<int> result = preorder(tree);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}