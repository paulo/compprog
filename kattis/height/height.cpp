#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    int n;
    for (int i = 0; i < t; i++) {
        cin >> n;

        int total = 0;
        vector<int> v(20);
        for (int j = 0; j < 20; j++) cin >> v[j];

        int j = 1;
        while (j < 20) {                    // current number being moved
            for (int k = 0; k < 20; k++) {  // index being tested
                if (v[j] < v[k] && k < j) {
                    v.insert(v.begin() + k, v[j]);
                    total += j < k ? 20 - k : j - k;
                    if (j < k) {
                        v.erase(v.begin() + j);
                    } else {
                        v.erase(v.begin() + j + 1);
                    }
                    break;
                }
            }
            j++;
        }

        cout << n << ' ' << total << endl;
    }

    return 0;
}
