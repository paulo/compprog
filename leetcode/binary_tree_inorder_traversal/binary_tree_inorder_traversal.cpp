#include <iostream>
#include <vector>

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
    vector<int> v;

   public:
    vector<int> inorderTraversal(TreeNode *root) {
        inorder(root);
        return v;
    }

    void inorder(TreeNode *root) {
        if (!root) return;

        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    Solution() { v = vector<int>(); }
};

int main() {
    TreeNode *root = new TreeNode(2, new TreeNode(1), new TreeNode(3));

    for (auto x : Solution().inorderTraversal(root)) {
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}
