#include <iostream>

using namespace std;

// (R1+R2)/2 = S
// R2 = 2*s - R1
int main() {
    int r1, s;
    cin >> r1 >> s;

    cout << 2 * s - r1;
}
