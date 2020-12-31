#include <iostream>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// The trick on this one is that you know that it's a perfect tree and that on
// each instance of the node, either there isn't a next node to connect to, or
// the node is already connected. It would be trickier if the tree wasn't
// perfect.
class Solution {
   public:
    Node* connect(Node* root) {
        if (!root) return NULL;

        if (root->left && root->right) {
            root->left->next = root->right;
        }

        if (root->next && root->right) {
            root->right->next = root->next->left;
        }

        root->left = connect(root->left);
        root->right = connect(root->right);

        return root;
    }
};

int main() {
    Node* n = new Node(1, new Node(2, new Node(4), new Node(5), NULL),
                       new Node(3, new Node(6), new Node(7), NULL), NULL);

    Solution().connect(n);

    return 0;
}
