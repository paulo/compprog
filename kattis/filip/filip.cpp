#include <iostream>

using namespace std;

int main() {
    int d1, d2;
    cin >> d1 >> d2;

    int n1=0, n2=0;
    n1 += d1 / 100; d1 -= (d1 / 100) * 100;
    n1 += (d1 / 10) * 10;  d1 -= (n1 / 10) * 10;
    n1 += d1 * 100;

    n2 += d2 / 100; d2 -= (d2 / 100) * 100;
    n2 += (d2 / 10) * 10;  d2 -= (n2 / 10) * 10;
    n2 += d2 * 100;

    if(n1>n2) cout << n1 << endl;
    else cout << n2 << endl;

    return 0;
}
