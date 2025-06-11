#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string serialize(TreeNode *root){
    if (root == NULL) return "";
    string s = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()){
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL) s.append("#,");
        else s.append(to_string(curr->val) + ',');
        if (curr != NULL){
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    return s;
}

TreeNode* deserialize(string data) {
    if(data.size() == 0)return NULL;
    stringstream s(data);
    string str;
    getline(s,str,',');
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        getline(s,str,',');
        if(str == "#")node->left = NULL;
        else{
        TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        getline(s,str,',');
        if(str == "#")node->right = NULL;
        else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main()
{
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    return 0;
}