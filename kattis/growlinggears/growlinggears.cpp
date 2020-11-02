#include <iostream>

using namespace std;

// From
// https://www.geeksforgeeks.org/maximum-and-minimum-value-of-a-quadratic-function/
// An alternative is to see the torque for what derivative of the function is 0,
// aka R = b / 2a
int main() {
    double t, n, a, b, c, maxGear;
    double maxVal, tmp;
    cin >> t;

    for (int i = 0; i < t; i++) {
        cin >> n;
        maxVal = 0;
        maxGear = 1;

        for (int j = 0; j < n; j++) {
            cin >> a >> b >> c;

            tmp = c - b * b / (4 * -a);

            if (tmp >= maxVal) {
                maxVal = tmp;
                maxGear = j + 1;
            }
        }

        cout << maxGear << endl;
    }

    return 0;
}
