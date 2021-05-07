#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back

vector<int> counts(2 * 10e5, 0);
vector<vector<int>> rels(2 * 10e5, vector<int>());

int pseudoinsert(int id) {
    if (rels[id].size() == 0) return 0;

    counts[id] = rels[id].size();

    for (auto r : rels[id]) {
        counts[id] += pseudoinsert(r);
    }

    return counts[id];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int parent;
    for (int i = 1; i < n; i++) {
        cin >> parent;
        rels[parent - 1].pb(i);
    }

    pseudoinsert(0);

    for (int i = 0; i < n; i++) {
        cout << counts[i] << " \n"[i == n - 1 ? 1 : 0];
    }

    return 0;
}
