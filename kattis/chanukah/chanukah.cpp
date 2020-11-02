#include <iostream>

using namespace std;

int main() {
    int p;
    cin >> p;

    int k, n;
    for (int i = 0; i < p; i++) {
        cin >> k >> n;

        cout << k << ' ' << ((n * (n + 1)) / 2) + n << endl;
    }

    return 0;
}
