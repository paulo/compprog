#include <iostream>

using namespace std;

int main() {
    string t1, t2;
    cin >> t1 >> t2;

    if (t1 == t2) {
        cout << "24:00:00" << endl;
        return 0;
    }

    int h1 = stoi(t1.substr(0, 2));
    int m1 = stoi(t1.substr(3, 2));
    int s1 = stoi(t1.substr(6, 2));
    int h2 = stoi(t2.substr(0, 2));
    int m2 = stoi(t2.substr(3, 2));
    int s2 = stoi(t2.substr(6, 2));

    int h3 = 0, m3 = 0, s3 = 0, carry = 0;
    if (s1 <= s2) {
        s3 = s2 - s1;
    } else {
        s3 = 60 - s1 + s2;
        carry = 1;
    }

    if (m1 <= m2) {
        m3 = m2 - m1 - carry;
        carry = 0;
        if (m3 < 0) {
            m3 = 60 + m3;
            carry = 1;
        }
    } else {
        m3 = 60 - m1 + m2 - carry;
        carry = 1;
    }

    if (h1 <= h2) {
        h3 = h2 - h1 - carry;
        if (h3 < 0) h3 = 24 + h3;
    } else {
        h3 = 24 - h1 + h2 - carry;
    }

    if (h3 < 10) cout << 0;
    cout << h3 << ':';
    if (m3 < 10) cout << 0;
    cout << m3 << ':';
    if (s3 < 10) cout << 0;
    cout << s3 << endl;

    return 0;
}
