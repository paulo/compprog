#include <iostream>

using namespace std;

typedef long long int ll;

// 3 4 3 5 4 1 2
struct bst_node {
    int value;
    ll left_size, right_size;
    bst_node *left, *right;

    bst_node(int _value) : value(_value) {
        left_size = right_size = 0;
        left = NULL;
        right = NULL;
    }
};

bst_node *insert(bst_node *root, int v) {
    if (!root) return new bst_node(v);

    if (v >= root->value) {  // to the right
        root->right_size++;
        root->right = insert(root->right, v);
    } else {  // to the left
        root->left_size++;
        root->left = insert(root->left, v);
    }

    return root;
}

// Number of ways to choose k objects from a set of n objects, ignoring order.
ll binomial(ll n, ll k) {
    if (k == 0 || k == n) return 1;
    return binomial(n - 1, k - 1) + binomial(n - 1, k);
}

ll count_binomial(bst_node *root) {
    if (!root) return 1;

    return binomial(root->left_size + root->right_size, root->right_size) *
           count_binomial(root->left) * count_binomial(root->right);
}

int main() {
    int n, aux;

    while (cin >> n && n != 0) {
        bst_node *tree;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            tree = insert(tree, aux);
        }

        cout << count_binomial(tree) << endl;
        tree = NULL;
    }

    return 0;
}
