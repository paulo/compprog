#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
typedef vector<point> vp;

double dot(point a, point b) { return real(a) * real(b) + imag(a) * imag(b); }

point closest_point(point a, point b, point c) {
    // Check if point is on the side of the segment
    if (dot(b - a, c - b) > 0) return b;
    if (dot(a - b, c - a) > 0) return a;

    double t = dot(c - a, b - a) / norm(b - a);
    return a + t * (b - a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    cout.precision(8);
    int ip, op, x, y;
    while (t-- > 0) {
        cin >> ip;

        vp inner(ip);
        for (int i = 0; i < ip; i++) {
            cin >> x >> y;
            inner[i] = point(x, y);
        }

        cin >> op;

        vp outer(op);
        for (int i = 0; i < op; i++) {
            cin >> x >> y;
            outer[i] = point(x, y);
        }

        // Distance between inner points and line segments of outer points
        double res = INT_MAX;
        point s1, s2, p, cp;
        for (int i = 0; i < ip; i++) {
            p = inner[i];
            for (int j = 0; j <= op; j++) {
                s1 = outer[j % op];
                s2 = outer[(j + 1) % op];

                cp = closest_point(s1, s2, p);
                res = min(res, abs(p - cp));
            }
        }

        cout << res / 2 << endl;
    }

    return 0;
}
