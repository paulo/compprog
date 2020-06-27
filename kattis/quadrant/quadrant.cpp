#include <iostream>

using namespace std;

int main() {
    int x, y, q;
    cin >> x >> y;

    if(x > 0) {
        q = y > 0 ? 1 : 4;
    } else {
        q = y > 0 ? 2 : 3;
    }

    cout << q << endl;
    return 0;
}
