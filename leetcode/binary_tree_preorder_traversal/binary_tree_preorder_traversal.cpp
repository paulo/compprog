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
    // root -> left -> right
    vector<int> preorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> res;

        if (root != NULL) s.push(root);

        while (!s.empty()) {
            TreeNode *x = s.top();
            s.pop();

            res.push_back(x->val);

            if (x->right != NULL) s.push(x->right);
            if (x->left != NULL) s.push(x->left);
        }

        return res;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode *root =
        new TreeNode(1, NULL, new TreeNode(2, new TreeNode(3), NULL));

    for (auto x : Solution().preorderTraversal(root)) {
        cout << x << endl;
    }
    return 0;
}
