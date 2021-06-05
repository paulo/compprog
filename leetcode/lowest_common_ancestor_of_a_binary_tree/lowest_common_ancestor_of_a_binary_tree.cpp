#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x), left(left), right(right) {}
};

// Can be done without the stack
class Solution {
   public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> qp = stack<TreeNode*>();
        stack<TreeNode*> qq = stack<TreeNode*>();

        findT(root, p, qp);
        findT(root, q, qq);

        while (qp.size() > qq.size()) qp.pop();
        while (qp.size() < qq.size()) qq.pop();

        TreeNode *tn1, *tn2;
        while (!qp.empty()) {
            tn1 = qp.top();
            qp.pop();
            tn2 = qq.top();
            qq.pop();

            if (tn1->val == tn2->val) {
                return tn1;
            }
        }

        return NULL;
    }

    bool findT(TreeNode* root, TreeNode* t, stack<TreeNode*>& q) {
        if (root == NULL) return false;

        q.push(root);

        if (root->val == t->val) {
            return true;
        }

        if (!findT(root->left, t, q) && !findT(root->right, t, q)) {
            q.pop();
        } else
            return true;

        return false;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode* root =
        new TreeNode(3,
                     new TreeNode(5, new TreeNode(6, NULL, NULL),
                                  new TreeNode(2, new TreeNode(7, NULL, NULL),
                                               new TreeNode(4, NULL, NULL))),
                     new TreeNode(1, new TreeNode(0, NULL, NULL),
                                  new TreeNode(8, NULL, NULL)));

    TreeNode* p = new TreeNode(5, NULL, NULL);
    TreeNode* q = new TreeNode(1, NULL, NULL);

    if (Solution().lowestCommonAncestor(root, p, q) != NULL) {
        cout << Solution().lowestCommonAncestor(root, p, q)->val << endl;
    }

    return 0;
}
