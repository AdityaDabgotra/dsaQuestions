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

bool same(TreeNode* root1,TreeNode* root2){
    if(root1 == NULL && root2 == NULL)return true;
    if(root1 == NULL || root2 == NULL)return false;
    if(root1->val != root2->val) return false;
    return same(root1->left,root2->left) && same(root1->right,root2->right);
}
int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    if(same(tree,tree)){
        cout<<"Both Trees are Same";
    }
    else cout<<"Both Trees are Different";
    return 0;
}
