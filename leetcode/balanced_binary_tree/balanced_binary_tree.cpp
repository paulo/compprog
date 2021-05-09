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
    bool balanced = true;

   public:
    bool isBalanced(TreeNode *root) {
        sameHeight(root, 0);
        return balanced;
    }

    int sameHeight(TreeNode *root, int curr) {
        if (root == NULL) return curr;

        int l = sameHeight(root->left, curr + 1);
        int r = sameHeight(root->right, curr + 1);

        if (l > r + 1 || r > l + 1) {
            balanced = false;
        }

        return max(l, r);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    return 0;
}
