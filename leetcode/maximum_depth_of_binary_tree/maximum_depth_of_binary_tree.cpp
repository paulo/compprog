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
   public:
    int maxDepth(TreeNode *root) {
        if (!root) return 0;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {
    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), NULL),
                                  new TreeNode(3, NULL, new TreeNode(5)));

    cout << Solution().maxDepth(root) << endl;

    return 0;
}
