#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    int min = n + 1;
    for (int i = 0; i < n; i++) {
        min = max(min, v[i] + i + 1);
    }

    cout << min + 1 << endl;

    return 0;
}
