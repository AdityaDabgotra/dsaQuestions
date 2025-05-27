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
int height(TreeNode* root) {
    if (root == NULL) return 0;
    int leftTree = height(root->left);
    int rightTree = height(root->right);
    return max(leftTree, rightTree) + 1;
}
void calc(TreeNode* root, int &dia) {
    if (root == NULL) return;
    int lh = height(root->left);
    int rh = height(root->right);
    dia = max(dia, lh + rh);
    calc(root->left, dia);
    calc(root->right, dia);
}
int diameter1(TreeNode* root) {
    int dia = 0;
    calc(root, dia);
    return dia; 
}

// Optimal Approach
int dia = 0;
int calc2(TreeNode* root){
    if(root == NULL)return 0;
    int lst = calc2(root->left);
    int rst = calc2(root->right);
    dia = max(lst+rst,dia);
    return max(lst,rst)+1;
}
int diameter2(TreeNode* root){
    int temp = calc2(root);
    return dia;
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    cout << "Diameter of Tree is:\t" << diameter2(tree) << endl;
    return 0;
}
