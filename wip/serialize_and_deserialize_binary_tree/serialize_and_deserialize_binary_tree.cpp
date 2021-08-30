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

class Codec {
   public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    TreeNode* root =
        new TreeNode(3, new TreeNode(9),
                     new TreeNode(20, new TreeNode(15), new TreeNode(7)));

    Codec c = Codec();
    string id = c.serialize(root);
    cout << id << endl;

    return 0;
}
