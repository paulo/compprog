#include <iostream>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
    int n, r, diff;
    cin >> n;

    int p1, p2, p3, p4;
    int s1, s2, s3, s4;
    for (int i = 0; i < n; i++) {
        cin >> s1 >> s2 >> p1 >> p2;
        cin >> s3 >> s4 >> p3 >> p4;

        r = p1;
        r = gcd(p2, r);
        r = gcd(p3, r);
        r = gcd(p4, r);

        s1 = s1 % r;
        s2 = s2 % r;
        s3 = s3 % r;
        s4 = s4 % r;

        // adjust row 1 column 1
        diff = r - s1;
        s1 = (s1 + diff) % r;
        s2 = (s2 + diff) % r;
        // s3 = (s3 + diff) % r;

        // adjust row 1 column 2
        diff = r - s2;
        s2 = (s2 + diff) % r;
        s4 = (s4 + diff) % r;

        // adjust row 2 column 1
        diff = r - s3;
        s3 = (s3 + diff) % r;
        s4 = (s4 + diff) % r;

        if (s4 == 0) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }

    return 0;
}
