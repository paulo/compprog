#include <iostream>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;

    int h = l > r ? l : r;

    if(h*2 == 0) {
        cout << "Not a moose" << endl;
    } else if(l == r) {
        cout << "Even " << h*2 << endl;
    } else {
        cout << "Odd " << h*2 << endl;
    }

    return 0;
}
