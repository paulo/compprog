#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, aux;
    cin >> n >> m;

    multiset<int> prices;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        // negative to invert the order and be able to use lower_bound
        prices.insert(-aux);
    }

    multiset<int>::iterator it;
    for (int i = 0; i < m; i++) {
        cin >> aux;

        it = prices.lower_bound(-aux);
        if (it != prices.end()) {
            cout << abs(*it) << endl;
            prices.erase(it);
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
