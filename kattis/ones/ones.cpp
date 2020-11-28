#include <iostream>

using namespace std;

// Taking advantage of modular arithmetic to avoid big ints
int main() {
    int n;

    while (cin >> n) {
        int r = n == 1 ? 0 : 1;  // remainder
        int c = 1;               // digit count
        while (r) {
            // r will always be some form of 1111...
            r = (r * 10 + 1) % n;
            c++;
        }

        cout << c << endl;
    }

    return 0;
}
