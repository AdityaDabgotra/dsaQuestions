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
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root->val < p->val && root->val < q->val){
        return lowestCommonAncestor(root->right,p,q);
    }
    else if(root->val > p->val && root->val > q->val){
        return lowestCommonAncestor(root->left,p,q);
    }
    else return root;
    return NULL;
}

int main(){
    TreeNode* tree = new TreeNode(5);
    tree->left = new TreeNode(3);
    tree->right = new TreeNode(7);

    tree->left->left = new TreeNode(1);
    tree->left->right = new TreeNode(4);
    tree->right->left = new TreeNode(6);
    tree->right->right = new TreeNode(8);

    TreeNode* ances = lowestCommonAncestor(tree,tree->left->left,tree->right->right);
    cout<<"THe LCA is "<<ances->val;
    return 0;
}