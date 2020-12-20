#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end(), greater<int>());

    long long int total = 0;
    for (int i = 2; i < n; i += 3) {
        total += v[i];
    }

    cout << total << endl;

    return 0;
}
