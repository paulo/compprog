#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    float q, y, t = 0;
    for (int i = 0; i < n; i++) {
        cin >> q >> y;
        t += q * y;
    }
    cout << fixed;
    cout << setprecision(3);
    cout << t << endl;

    return 0;
}
