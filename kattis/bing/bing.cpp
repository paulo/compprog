#include <iostream>
#include <cstring>

using namespace std;

struct node {
    node* children[26];
    bool is_end;
    int times;
    node() {
        memset(children, 0, sizeof(children));
        is_end = false;
        times = 0;
    }
};

void insert(node* nd, char *s) {
    if (*s) {
        if (!nd->children[*s - 'a']) nd->children[*s - 'a'] = new node();
        else nd->children[*s - 'a']->times++;

        insert(nd->children[*s - 'a'], s + 1);
    } else {
        nd->is_end = true;
    }
}

int times(node* nd, char *s) {
    if (*s) {
        if (!nd->children[*s - 'a']) return 0;

        return times(nd->children[*s - 'a'], s + 1);
    } else {
        return nd->times;
    }
}

int main() {
    int n;
    cin >> n;

    node *trie = new node();

    string s;
    for(int i = 0; i < n; i++) {
        cin >> s;

        insert(trie, &s[0]);
        cout << times(trie, &s[0]) << endl;
    }
}
