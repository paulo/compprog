#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<bool> vb;

#define pb push_back

using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;

    vector<cd> a0(n / 2), a1(n / 2);
    for (int i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);

    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int d1, d2;
    cin >> d1 >> d1;

    vector<cd> a(d1 + 1, 0);
    for (int i = 0; i <= d1; i++) cin >> a[i];
    cin >> d2;
    vector<cd> b(d2 + 1, 0);
    for (int i = 0; i <= d2; i++) cin >> b[i];

    int n = 1;
    while (n < a.size() + b.size()) n <<= 1;
    a.resize(n);
    b.resize(n);

    fft(a, false);
    fft(b, false);
    for (int i = 0; i < n; i++) a[i] *= b[i];
    fft(a, true);

    cout << d1 + d2 << endl;
    for (int i = 0; i < d1 + d2 + 1; i++) {
        cout << int(round(a[i].real())) << " ";
    }
    cout << endl;

    return 0;
}
