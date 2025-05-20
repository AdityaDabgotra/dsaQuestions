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
int height(TreeNode* root){
    if(root == NULL)return 0;
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}
bool balanced1(TreeNode* root){
    if(root == NULL)return true;
    int leftSubTree = height(root->left);
    int rightSubTree = height(root->right);
    if(abs(leftSubTree - rightSubTree) > 1)return false;
    return true;
}

// Optimal Approach
int check(TreeNode* root) {
    if (root == NULL)return 0;

    int left = check(root->left);
    if (left == -1) return -1; 

    int right = check(root->right);
    if (right == -1) return -1;

    if (abs(left - right) > 1)return -1;
    return max(left, right) + 1;  // return height
}
bool balanced2(TreeNode* root) {
    return check(root) != -1;
}

int main(){
    TreeNode* tree = new TreeNode(1);

    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);

    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    if(balanced2(tree)){
        cout<<"Tree is Balanced";
    }
    else cout<<"Tree is not Balanced";
    
    return 0;
}