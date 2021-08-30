#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

struct suffix_array {
    struct entry {
        pair<int, int> nr;
        int p;
        bool operator<(const entry& other) const { return nr < other.nr; }
    };
    string s;
    int n;
    vector<vector<int> > P;
    vector<entry> L;
    vi idx;

    suffix_array(string _s) : s(_s), n(s.size()) {
        L = vector<entry>(n);
        P.push_back(vi(n));
        idx = vi(n);
        for (int i = 0; i < n; i++) {
            P[0][i] = s[i];
        }
        for (int stp = 1, cnt = 1; (cnt >> 1) < n; stp++, cnt <<= 1) {
            P.push_back(vi(n));
            for (int i = 0; i < n; i++) {
                L[i].p = i;
                L[i].nr = make_pair(P[stp - 1][i],
                                    i + cnt < n ? P[stp - 1][i + cnt] : -1);
            }
            sort(L.begin(), L.end());
            for (int i = 0; i < n; i++) {
                if (i > 0 && L[i].nr == L[i - 1].nr) {
                    P[stp][L[i].p] = P[stp][L[i - 1].p];
                } else {
                    P[stp][L[i].p] = i;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            idx[P[P.size() - 1][i]] = i;
        }
    }
};
int main() {
    int l;
    cin >> l;

    string s;
    cin >> s;

    return 0;
}
