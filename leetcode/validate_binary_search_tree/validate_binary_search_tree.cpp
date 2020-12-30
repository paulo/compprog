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
    bool isValidBST(TreeNode *root) {
        if (!root) return true;

        return isValid(root->left, &root->val, NULL) &&
               isValid(root->right, NULL, &root->val);
    }

   private:
    bool isValid(TreeNode *root, int *max, int *min) {
        if (!root) return true;
        if ((max && root->val >= *max) || (min && root->val <= *min))
            return false;

        return isValid(root->left, &root->val, min) &&
               isValid(root->right, max, &root->val);
    }
};

int main() {
    TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    cout << Solution().isValidBST(root) << endl;

    return 0;
}

// Alternative solution using inorder traversal of the tree, maintaing the
// lowest element The new element must always be higher than the last
// class Solution {
// // We use Integer instead of int as it supports a null value.
// private Integer prev;

// public boolean isValidBST(TreeNode root) {
// prev = null;
// return inorder(root);
// }

// private boolean inorder(TreeNode root) {
// if (root == null) {
// return true;
// }
// if (!inorder(root.left)) {
// return false;
// }
// if (prev != null && root.val <= prev) {
// return false;
// }
// prev = root.val;
// return inorder(root.right);
// }
// }
