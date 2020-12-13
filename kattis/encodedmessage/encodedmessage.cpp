#include <math.h>

#include <iostream>

using namespace std;

int main() {
    int n, d;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        d = ceil(sqrt(s.length()));

        for (int j = 0; j < d; j++) {
            for (int k = 1; k <= d; k++) {
                cout << s.at(d * k - j - 1);
            }
        }

        cout << endl;
    }

    return 0;
}
