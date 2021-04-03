#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
typedef vector<int> vi;

#define pb push_back

// rat basically denotes a fraction. normal values have inv to false, values
// like 1/value have inv to true
struct rat {
    int value;
    bool inv;
    rat(int _value, bool _inv) {
        value = _value;
        inv = _inv;
    }
};

struct rat_compare {
    bool operator()(const pair<rat, int>& r1, const pair<rat, int>& r2) const {
        if (!r1.first.inv && !r2.first.inv)
            return r1.first.value < r2.first.value;

        if (r1.first.inv && r2.first.inv)
            return r1.first.value > r2.first.value;

        return r1.first.inv;
    }
};

vector<pair<rat, int>> conversions;
vector<pair<int, rat>> adj[12];

void dfs(int start, int prev, rat r) {
    for (auto a : adj[start]) {
        if (a.first == prev) continue;
        int rr = 1;
        bool i = false;
        if ((r.inv && a.second.inv) || (!r.inv && !a.second.inv)) {
            rr = r.value * a.second.value;
            i = r.inv;
        } else if (r.value > a.second.value) {
            rr = r.value / a.second.value;
            i = r.inv;
        } else {
            rr = a.second.value / r.value;
            i = a.second.inv;
        }
        conversions[a.first] = {rat(rr, i), a.first};
        dfs(a.first, start, rat(rr, i));
    }
}

// Note: Fuck this problem in c++, had to do a bunch of work due to the floating
// point errors
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    ld aux;
    string s, saux;
    cout << fixed;
    while (cin >> n && n != 0) {
        unordered_map<string, int> m2i;
        unordered_map<int, string> i2m;
        for (int i = 0; i < n; i++) {
            cin >> s;
            m2i[s] = i;
            i2m[i] = s;
        }

        for (int i = 0; i < 12; i++) adj[i] = vector<pair<int, rat>>();

        for (int i = 0; i < n - 1; i++) {
            cin >> s >> saux >> aux >> saux;

            adj[m2i[s]].pb({m2i[saux], rat(aux, false)});
            adj[m2i[saux]].pb({m2i[s], rat(aux, true)});
        }

        conversions = vector<pair<rat, int>>(n, {rat(1, false), 0});
        // calculate ratios on tree (no need to track visited nodes, just the
        // previous one)
        dfs(0, -1, rat(1, false));

        sort(conversions.begin(), conversions.end(), rat_compare());

        vector<ll> res(n);
        long double r = conversions[0].first.value;
        if (!conversions[0].first.inv) r = 1 / r;
        for (int i = 1; i < n; i++) {  // normalize
            if (conversions[i].first.inv) {
                res[i] = r / conversions[i].first.value;
            } else {
                res[i] = conversions[i].first.value * r;
            }
        }

        cout << 1 << i2m[conversions[0].second];
        for (int i = 1; i < n; i++) {
            cout << " = " << res[i] << i2m[conversions[i].second];
        }
        cout << endl;
    }

    return 0;
}
