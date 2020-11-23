#include <algorithm>
#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

struct pair_compare {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second > p2.second;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) cin >> weights[i];

    sort(weights.begin(), weights.end(), greater<int>());

    vector<pair<int, int>> moneys;
    int x, p;
    for (int i = 0; i < m; i++) {
        cin >> x >> p;

        moneys.push_back(make_pair(x, p));
    }

    sort(moneys.begin(), moneys.end(), pair_compare());

    long long int total = 0;

    int k = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < moneys[i].first && k < n; j++) {
            ll w = weights[k], pr = moneys[i].second;
            total += w * pr;
            k++;
        }
    }

    cout << total << endl;

    return 0;
}
