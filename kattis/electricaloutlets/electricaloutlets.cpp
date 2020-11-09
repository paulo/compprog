#include <iostream>

using namespace std;

int main() {
    int t, n, s, aux;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        s = 0;
        for (int j = 0; j < n; j++) {
            cin >> aux;
            s += aux;
        }

        cout << s - n + 1 << endl;
    }

    return 0;
}
