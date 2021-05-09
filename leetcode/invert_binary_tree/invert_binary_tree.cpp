#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == NULL) return root;

        TreeNode *aux = NULL;
        aux = root->left;
        root->left = root->right;
        root->right = aux;
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};

void print(TreeNode *root) {
    if (root) {
        cout << root->val << endl;
        print(root->left);
        print(root->right);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));
    print(root);
    Solution().invertTree(root);
    print(root);

    return 0;
}
