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

// Bruteforce Approach

// Traverse through the Tree and determine the Path of each node
// and return the max value


// Optimised Approach
int max_sum = INT_MIN;
int trav(TreeNode* root){
    if(root == NULL)return 0;
    int lst = max(0, trav(root->left));
    int rst = max(0, trav(root->right));
    max_sum = max(max_sum,lst+rst+root->val);
    return max(lst,rst)+root->val;
}
int maxPath1(TreeNode* root){
    int temp = trav(root);
    return max_sum;
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    cout << "Max Path Sum of Tree is:\t" << maxPath1(tree) << endl;
    return 0;
}
