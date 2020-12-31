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

// From
// https://www.geeksforgeeks.org/construct-tree-from-given-inorder-and-preorder-traversal/
class Solution {
    int preOrderIndex;

   public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) return NULL;
        return build(preorder, inorder, 0, inorder.size() - 1);
    }

    // To the left of these are the elements on the left side of this node,
    // same to the right
    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int inMinIndex,
                    int inMaxIndex) {
        if (inMinIndex > inMaxIndex) return NULL;

        TreeNode *root = new TreeNode(preorder[preOrderIndex++]);
        root->left = NULL;
        root->right = NULL;

        if (inMinIndex == inMaxIndex) return root;

        auto inOrderIndex =
            find(inorder.begin(), inorder.end(), root->val) - inorder.begin();

        root->left = build(preorder, inorder, inMinIndex, inOrderIndex - 1);
        root->right = build(preorder, inorder, inOrderIndex + 1, inMaxIndex);

        return root;
    }

    Solution() { preOrderIndex = 0; }

    void printInorder(TreeNode *node) {
        if (node == NULL) return;

        printInorder(node->left);

        cout << node->val << ' ';

        printInorder(node->right);
    }
};

// Inorder (Left, Root, Right)
// [9,3,15,20,7]
//
// Preorder (Root, Left, Right)
// [3,9,20,15,7]

//    3
//   / \
//  9  20
//    /  \
//   15   7
int main() {
    vector<int> preorder{3, 9, 20, 15, 7};
    vector<int> inorder{9, 3, 15, 20, 7};

    TreeNode *t = Solution().buildTree(preorder, inorder);

    Solution().printInorder(t);

    cout << endl;

    return 0;
}
