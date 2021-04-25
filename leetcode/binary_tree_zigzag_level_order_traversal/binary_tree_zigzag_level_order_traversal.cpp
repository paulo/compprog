#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

class Solution {
    vector<vector<int>> res;

   public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int maxLevel = inorder(root, 0);

        res.resize(maxLevel);
        for (int i = 0; i < maxLevel; i++) {
            if (i % 2 != 0) reverse(res[i].begin(), res[i].end());
        }

        return res;
    }

    int inorder(TreeNode* root, int level) {
        if (!root) return 0;

        res[level].push_back(root->val);

        return max(inorder(root->left, level + 1),
                   inorder(root->right, level + 1)) +
               1;
    }

    Solution() { res = vector<vector<int>>(2000, vector<int>()); }
};

int main() {
    // [3,9,20,null,null,15,7]
    // [1,2,3,4,null,null,5]
    TreeNode* root =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    // TreeNode* root = new TreeNode(1, new TreeNode(2, new TreeNode(4), NULL),
    // new TreeNode(3, NULL, new TreeNode(5)));

    vector<vector<int>> r = Solution().zigzagLevelOrder(root);

    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i].size(); j++) {
            cout << r[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
