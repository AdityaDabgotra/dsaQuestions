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
bool find(TreeNode* root,TreeNode* target,vector<TreeNode*>&arr){
    if(root == NULL)return false;
    arr.push_back(root);

    if(root == target)return true;
    if(find(root->left,target,arr) || find(root->right,target,arr)){
        return true;
    }
    arr.pop_back();
    return false;

}
TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL)return NULL;
    vector<TreeNode*>arr1;
    vector<TreeNode*>arr2;
    find(root,p,arr1);
    find(root,q,arr2);
    int size = min(arr1.size(),arr2.size());
    for (int i = 1; i < size; i++){
        if(arr1[i] != arr2[i]){
            return arr1[i-1];
        }
    }
    return arr1[size-1];
} 

// Optimal Approach
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root==p || root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor2(root->left,p,q);
        TreeNode* right = lowestCommonAncestor2(root->right,p,q);
        if(left==NULL){
            return right;
        }
        else if(right==NULL){
            return left;
        }
        else{
            return root;
        }

    }
int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    TreeNode* num1 = tree->left;
    TreeNode* num2 = tree->left->right->right;

    TreeNode* node = lowestCommonAncestor2(tree,num1,num2);
    cout<<"The Lowest Common Ansestor is "<<node->val;
    return 0;
}