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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;

        if (root->val == targetSum && root->left == NULL && root->right == NULL)
            return true;

        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(4), NULL),
                                  new TreeNode(3, NULL, new TreeNode(5)));

    cout << Solution().hasPathSum(root, 22) << endl;

    return 0;
}
