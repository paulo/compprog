#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

vector<int> divs(int n) {
    vector<int> v;
    for (int i = 1; i <= floor(sqrt(n)); i++) {
        if (n % i == 0) {
            if (n / i == i)
                v.push_back(i);
            else {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }

    return v;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    if (n == 2) {
        if (v[0] < v[1]) swap(v[0], v[1]);
        vector<int> ds = divs(v[0] - v[1]);

        for (auto x : ds) {
            if (x <= 1) continue;
            if (v[0] % x == v[1] % x) cout << x << " ";
        }
        cout << endl;
        return 0;
    }

    sort(v.begin(), v.end(), greater<int>());

    int m = INT_MAX;
    for (int i = 0; i < n - 2; i++) {
        m = min(m, gcd(v[i] - v[i + 1], v[i + 1] - v[i + 2]));
    }

    vector<int> ds = divs(m);

    for (int j = 0; j < int(ds.size()); j++) {
        if (ds[j] <= 1) continue;
        int prev = -1;
        bool f = true;

        for (int i = 0; i < n && f; i++) {
            if (prev == -1 || prev == v[i] % ds[j]) {
                prev = v[i] % ds[j];
                continue;
            } else
                f = false;
        }
        if (f) cout << ds[j] << " \n"[j == int(ds.size()) ? 1 : 0];
    }

    return 0;
}
