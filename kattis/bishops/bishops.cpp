#include <iostream>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n <= 2) {
            cout << n << endl;
        } else {
            cout << n + n - 2 << endl;
        }
    }

    return 0;
}
