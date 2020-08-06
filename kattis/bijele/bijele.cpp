#include <iostream>

using namespace std;

// One king
// One queen
// Two rooks
// Two bishops
// Two knights
// Eight pawns

int main() {
    int x;
    int ps[6] = { 1, 1, 2, 2, 2, 8 };

    for(int i = 0; i < 6; i++) {
        cin >> x;
        cout << ps[i] - x << ' ';
    }

    cout << endl;

    return 0;
}
