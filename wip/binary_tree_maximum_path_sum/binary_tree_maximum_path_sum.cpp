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
    int currentMax = INT_MIN;

   public:
    int maxPathSum(TreeNode *root) {
        if (!root) return 0;

        traverse(root);

        return currentMax;
    }

    int traverse(TreeNode *root) {
        if (!root) return 0;

        int current = root->val;
        int left = maxPathSum(root->left);
        int right = maxPathSum(root->right);
        currentMax = max(currentMax, left);
        currentMax = max(currentMax, right);
        current = max(
            current,
            max(current + left, max(current + right, current + right + left)));
        // current = max(current, current + right);
        // current = max(current, current + right + left);
        currentMax = max(currentMax, current);

        cout << current << endl;

        return current;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode *root =
        new TreeNode(-10, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    cout << Solution().maxPathSum(root) << endl;

    return 0;
}
