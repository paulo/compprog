#include <iostream>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        if (!root->left && !root->right) return true;

        return isSym(root->left, root->right);
    }

    bool isSym(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left && right) return false;
        if (left && !right) return false;

        return left->val == right->val && isSym(left->left, right->right) &&
               isSym(left->right, right->left);
    }
};

int main() {
    TreeNode *root =
        new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)),
                     new TreeNode(2, new TreeNode(4), new TreeNode(5)));

    cout << Solution().isSymmetric(root) << endl;

    return 0;
}
