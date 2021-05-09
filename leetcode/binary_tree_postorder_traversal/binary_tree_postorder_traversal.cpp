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
    // left -> right -> root
    // can be done with two stacks instead of the map
    vector<int> postorderTraversal(TreeNode *root) {
        stack<TreeNode *> s;
        vector<int> res;
        unordered_map<TreeNode *, bool> visited;

        if (root != NULL) s.push(root);

        while (!s.empty()) {
            TreeNode *x = s.top();

            if ((x->right == NULL && x->left == NULL) || visited[x]) {
                res.push_back(x->val);
                s.pop();
                continue;
            }

            visited[x] = true;

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

    for (auto x : Solution().postorderTraversal(root)) {
        cout << x << endl;
    }

    return 0;
}
