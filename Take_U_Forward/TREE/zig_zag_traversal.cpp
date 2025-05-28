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

vector<vector<int>>zigzagLevelOrder(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    bool flag = false;
    vector<vector<int>>ans;
    if(root == NULL)return ans;
    while (!q.empty()){
        int size = q.size();
        vector<int>level;
        for (int i = 0; i < size; i++){
            TreeNode *node = q.front();
            q.pop();
            if(node->left != NULL)q.push(node->left);
            if(node->right != NULL)q.push(node->right);
            level.push_back(node->val);
        }
        if(flag){
            reverse(level.begin(),level.end());
            ans.push_back(level);
        }
        else{
            ans.push_back(level);
        }
        flag = flag == true ? false : true;
    }
    return ans;
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    cout<<"Zig Zag Traversal of Tree is:\n";
    vector<vector<int>>result = zigzagLevelOrder(tree);
    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
