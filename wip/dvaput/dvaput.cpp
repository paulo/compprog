#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

struct suffix_array {
    struct entry {
        pair<int, int> nr;
        int p;
        bool operator <(const entry &other) const {
            return nr < other.nr;
        }
    };

    string s;
    int n;
    vector<vi> p;
    vector<entry> l;
    vi idx;

    suffix_array(string _s) : s(_s), n(s.size()) {
        l = vector<entry>(n);
        p.push_back(vi(n));
        idx = vi(n);

        for (int i = 0; i < n; i++) {
            p[0][i] = s[i];
        }

        for (int stp = 1, cnt = 1; (cnt >> 1) < n; stp++, cnt <<= 1) {
            p.push_back(vi(n));
            for (int i = 0; i < n; i++) {
                l[i].p = i;
                l[i].nr = make_pair(p[stp - 1][i], i + cnt < n ? p[stp - 1][i + cnt] : -1);
            }
            sort(l.begin(), l.end());
            for (int i = 0; i < n; i++) {
                if (i > 0 && l[i].nr == l[i - 1].nr) {
                    p[stp][l[i].p] = p[stp][l[i - 1].p];
                } else {
                    p[stp][l[i].p] = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            idx[p[p.size() - 1][i]] = i;
        }
    }
};

struct node {
    node* children[26];
    bool is_end;
    bool visited;
    node() {
        memset(children, 0, sizeof(children));
        is_end = false;
        visited = false;
    }
};

int mx = 0;

void insert(node* nd, char *s, int l) {
    if (*s) {
        if (!nd->children[*s - 'a']) nd->children[*s - 'a'] = new node();
        else nd->children[*s - 'a']->visited = true;

        insert(nd->children[*s - 'a'], s + 1, l + (nd->visited ? 1 : 0));
    } else {
        mx = max(mx, l);
        nd->is_end = true;
    }
}

int main() {
    int l;
    cin >> l;

    string s;
    cin >> s;

    node *trie = new node();

    string sub;
    for(int i=0; i < l; i++){
        sub = s.substr(i, s.length() - i);
        // cout << sub << endl;
        insert(trie, &sub[0], 0);
    }

    cout << mx << endl;
}
