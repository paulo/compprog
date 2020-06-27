#include <iostream>
#include <vector>
#include <map>
#include <numeric>

using namespace std;

struct segment_tree {
    segment_tree *left, *right;
    int from, to, value;
    segment_tree(int from, int to)
        : left(NULL), right(NULL), from(from), to(to), value(0) { }
};

// Simplified segment tree since every value starts as 0
segment_tree* build(int l, int r) {
    if (l > r) return NULL;
    segment_tree *res = new segment_tree(l, r);
    if (l == r) return res;

    int m = (l + r) / 2;
    res->left = build(l, m);
    res->right = build(m + 1, r);

    return res;
}

// query returns the amount of bits to 1 between l and r
int query(segment_tree *tree, int l, int r) {
    if (tree == NULL) return 0;
    if (l <= tree->from && tree->to <= r) return tree->value;
    if (tree->to < l) return 0;
    if (r < tree->from) return 0;
    return query(tree->left, l, r) + query(tree->right, l, r);
}

// flip flips the bit in that index and returns the adjustment to be made on the rest of the nodes
int flip(segment_tree *tree, int i) {
    if (tree == NULL) return 0;

    // If tree does not accout for the i'th bit
    if (tree->to < i) return 0;
    if (tree->from > i) return 0;

    int aux = tree->value;

    if (tree->from <= i && tree->to >= i) { // it accounts for the i'th bit
        tree->value += flip(tree->left, i) + flip(tree->right, i);
    }

    if (tree->from == i && tree->to == i) { // it is the i'th bit
        tree->value = aux == 1 ? 0 : 1;
    }

    return tree->value - aux;
}

int main() {
    int N, K;
    cin >> N >> K;

    char op;
    int l, k, r;
    segment_tree *t = build(0, N);
    for(int i=0; i<K;i++){
        cin >> op;

        if(op == 'F'){
            cin >> k;
            flip(t, k);
        } else {
            cin >> l >> r;
            cout << query(t, l, r) << endl;
        }
    }

    return 0;
}
