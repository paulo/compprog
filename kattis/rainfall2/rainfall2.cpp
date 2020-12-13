#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    double l, k, t1, t2, h;
    cin >> l >> k >> t1 >> t2 >> h;

    // if observed is lower than the leak, f1 and f2 are equal to h
    if (h < l) {
        cout << fixed << setprecision(6) << h << ' ' << h;
        return 0;
    }

    double h2 = h + k * t2;  // level at the end of the rainfall (not counting
                             // possible water lost during t2)

    // Considering R as the rainfall rate:
    // R * T1 is the total amount of rainfall and we have
    // L + (R-K)*(T1-(L/R)) = H2, where T1-(L/R) is the amount of time between
    // reaching the leak and the end of the rainfall. Thus, we want to know
    // R*T1. We can derive this into a quadratic equation and apply the
    // quadratic formula to:  T1*R^2 + R (-K*T1-H2) + L*K = 0
    double a = t1;
    double b = -k * t1 - h2;
    double c = l * k;
    double f = (-b + sqrt(b * b - 4 * a * c)) / 2;

    cout << fixed << setprecision(6) << (h <= l ? h : f) << " "
         << (h < l ? h : f) << endl;

    return 0;
}

