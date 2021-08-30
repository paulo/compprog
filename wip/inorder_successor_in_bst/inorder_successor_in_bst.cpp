#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// This solution can be improved by cutting the search space according to the
// properties of BSTs (elements on the left are smaller, on the right are
// larger).
class Solution {
    bool next;

   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        return inorder(root, p);
    }

    TreeNode* inorder(TreeNode* root, TreeNode* p) {
        if (!root) return NULL;

        if (root->val == p->val) {
            next = true;
            if (root->right != NULL)
                return allLeft(root->right);
            else
                return NULL;
        }

        TreeNode* left = inorder(root->left, p);
        if (left != NULL) return left;

        if (next) return root;

        TreeNode* right = inorder(root->right, p);
        if (right != NULL) return right;

        return NULL;
    }

    TreeNode* allLeft(TreeNode* root) {
        if (root->left != NULL)
            return allLeft(root->left);
        else
            return root;
    }

    Solution() { next = false; }
};

int main() {
    // [ 5, 3, 6, 1, 4, null, null, null, 2 ]

    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->left->right = new TreeNode(2);
    root->left->right = new TreeNode(4);

    // TreeNode* root = new TreeNode(2);
    // root->left = new TreeNode(1);
    // root->right = new TreeNode(3);

    auto s = Solution().inorderSuccessor(root, root->right);

    if (s) {
        cout << s->val << endl;
    } else {
        cout << "nope" << endl;
    }

    return 0;
}
