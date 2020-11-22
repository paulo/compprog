#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, total = 0;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        total += v[i];
    }

    sort(v.begin(), v.end());

    for (int i = n - 3; i >= 0; i -= 3) {
        total -= v[i];
    }

    cout << total << endl;

    return 0;
}
