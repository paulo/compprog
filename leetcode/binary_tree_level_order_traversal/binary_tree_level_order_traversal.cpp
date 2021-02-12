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
    vector<vector<int>> res;

   public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        leftToRightTraversal(root, 0);

        return res;
    }

    void leftToRightTraversal(TreeNode *root, int level) {
        if (!root) return;

        if (res.size() <= level) res.push_back(vector<int>());
        res[level].push_back(root->val);

        leftToRightTraversal(root->left, level + 1);
        leftToRightTraversal(root->right, level + 1);
    }

    Solution() { res = vector<vector<int>>(); }
};

int main() {
    TreeNode *root = new TreeNode(3, new TreeNode(9, NULL, NULL),
                                  new TreeNode(20, new TreeNode(15, NULL, NULL),
                                               new TreeNode(7, NULL, NULL)));

    auto r = Solution().levelOrder(root);

    for (auto i : r) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
