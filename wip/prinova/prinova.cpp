#include <stdlib.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<ll> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    sort(vc.begin(), vc.end());

    ll a, b;
    cin >> a >> b;

    if (a >= vc[n - 1]) {
        if (b % 2 == 0) b--;
        cout << b << endl;
        return 0;
    }

    if (b <= vc[0]) {
        if (a % 2 == 0) a++;
        cout << a << endl;
        return 0;
    }

    // i tracks the current number being tried out, j tracks the index in v
    ll i = a, maxDiff = 1, diff;
    int j = 0;
    if (i % 2 == 0) i++;
    ll currI = i;
    for (j = 0; j < vc.size(); j++) {
        if (vc[j] >= currI) break;
        maxDiff = i - vc[j];
    }

    while (i <= b && j < vc.size()) {
        // if out of currently tested interval
        if (i >= vc[j + 1] && i < vc[j]) {
            throw std::runtime_error("invalid");
        }

        if (i >= vc[j + 1]) {
            j++;
            continue;
        }

        diff = min(abs(vc[j] - i), abs(vc[j + 1] - i));
        if (diff >= maxDiff) {
            currI = i;
            maxDiff = max(maxDiff, diff);
        }

        i += 2;
    }

    if (i <= b) {
        if (b % 2 == 0) b--;
        if (maxDiff <= b - currI) {
            currI = b;
        }
        // throw std::runtime_error("invalid");
    }

    cout << currI << endl;

    return 0;
}
