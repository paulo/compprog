#include <iostream>

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
    int kth;

   public:
    int kthSmallest(TreeNode *root, int k) {
        inorder(root, k, 0);
        return kth;
    }

    int inorder(TreeNode *root, int k, int curr) {
        if (!root) return curr;

        int l = inorder(root->left, k, curr);  // we're at node l + 1
        if (l + 1 == k) kth = root->val;
        int r = inorder(root->right, k, l + 1);

        return r;
    }
};

int main() {
    TreeNode *t = new TreeNode(
        5,
        new TreeNode(3, new TreeNode(2, new TreeNode(1, NULL, NULL), NULL),
                     new TreeNode(4, NULL, NULL)),
        new TreeNode(6, NULL, NULL));

    // TreeNode *t =
    // new TreeNode(3, new TreeNode(1, NULL, new TreeNode(2, NULL, NULL)),
    // new TreeNode(4, NULL, NULL));

    cout << Solution().kthSmallest(t, 3) << endl;

    return 0;
}
