#include <iostream>

using namespace std;

int main() {
    char c1 = '\0', c2 = '\0';

    while (cin >> c1) {
        if (c1 == 's' && c2 == 's') {
            cout << "hiss" << endl;
            return 0;
        }
        c2 = c1;
    }

    cout << "no hiss" << endl;

    return 0;
}
