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
    int countUnivalSubtrees(TreeNode *root) {
        if (!root) return 0;

        return count(root, root->val + 1).first;  // just to be different
    }

    pair<int, bool> count(TreeNode *root, int prev) {
        if (!root) return {0, true};
        if (root->left == NULL && root->right == NULL)
            return {1, prev == root->val};

        auto left = count(root->left, root->val);
        auto right = count(root->right, root->val);
        int res = left.first + right.first;

        if (left.second && right.second)
            return {res + 1, prev == root->val};
        else
            return {res, false};
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode *root =
        new TreeNode(5, new TreeNode(1, new TreeNode(5), new TreeNode(5)),
                     new TreeNode(5, NULL, new TreeNode(5)));

    cout << Solution().countUnivalSubtrees(root) << endl;

    return 0;
}
