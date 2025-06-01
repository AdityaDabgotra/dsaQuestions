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

vector<int>bottomView(TreeNode* root){
    vector<int>ans;
    map<int,int>mp; // {x,val}
    queue<pair<TreeNode*,int>>q;
    q.push({root,0});
    while(!q.empty()){
        auto itr = q.front();
        q.pop();
        TreeNode* node = itr.first;
        int x = itr.second;

        mp[x] = node->val;
        
        if(node->left)q.push({node->left,x-1});
        if(node->right)q.push({node->right,x+1});
    }
    for(auto itr: mp){
        ans.push_back(itr.second);
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
    vector<int>result = bottomView(tree);
    for (int i = 0; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    return 0;
}