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
vector<vector<int>> allTraversal(TreeNode* root){
    stack<pair<TreeNode*,int>>st;
    vector<int>pre;
    vector<int>in;
    vector<int>post;
    st.push({root,1});
    while (!st.empty()){
        auto &itr = st.top();
        TreeNode* node = itr.first;
        int state = itr.second;
        if(state == 1){
            st.pop();
            pre.push_back(node->val);
            state++;
            st.push({node,state});
            if(node->left)st.push({node->left,1});
        }
        else if (state == 2){
            st.pop();
            in.push_back(node->val);
            state++;
            st.push({node,state});
            if(node->right)st.push({node->right,1});
        }
        else{
            st.pop();
            post.push_back(node->val);
        }
    }
    return {pre,in,post};
    

}
int main(){
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    vector<vector<int>>result = allTraversal(tree);

    for (int i = 0; i < result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}