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

int width(TreeNode* root) {
    if (!root) return 0;

    unsigned long long max_width = 0;
    queue<pair<TreeNode*, unsigned long long>> q;
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        unsigned long long level_min = q.front().second;
        unsigned long long first = 0, last = 0;

        for (int i = 0; i < size; i++) {
            auto [node, index] = q.front();
            q.pop();
            index -= level_min;

            if (i == 0) first = index;
            if (i == size - 1) last = index;

            if (node->left) q.push({node->left, 2 * index});
            if (node->right) q.push({node->right, 2 * index + 1});
        }

        max_width = max(max_width, last - first + 1);
    }

    return static_cast<int>(max_width);
}

int main() {
    TreeNode* tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->right = new TreeNode(3);
    tree->left->left = new TreeNode(4);
    tree->left->right = new TreeNode(5);
    tree->left->right->left = new TreeNode(6);
    tree->left->right->right = new TreeNode(7);

    int result = width(tree);
    cout<<"The Maximum Width of Binary tree is  "<<result;
    return 0;
}