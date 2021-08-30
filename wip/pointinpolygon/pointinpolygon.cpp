#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<int> point;
typedef vector<point> vp;

#define pb push_back

// check if q lies between p and r
bool onSegment(point p, point q, point r) {
    if (real(q) <= max(real(p), real(r)) && real(q) >= min(real(p), real(r)) &&
        imag(q) <= max(imag(p), imag(r)) && imag(q) >= min(imag(p), imag(r)))
        return true;
    return false;
}

int orientation(point p, point q, point r) {
    ll val = (imag(q) - imag(p)) * (real(r) - real(q)) -
             (real(q) - real(p)) * (imag(r) - imag(q));

    if (val == 0) return 0;    // colinear
    return (val > 0) ? 1 : 2;  // clock or counterclock wise
}

bool intersect(point p1, point q1, point p2, point q2) {
    // Find the four orientations needed for general and
    // special cases
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4) return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and p2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;  // Doesn't fall in any of the above cases
}

// bool intersect(point p, point pinf, point p1, point p2) {
// int c1, c2, c3, c4;
// c1 = orientation(p1, p2, p);
// c2 = orientation(p1, p2, pinf);
// c3 = orientation(p, pinf, p1);
// c4 = orientation(p, pinf, p2);

// // c1 = cross(p - p1, p - p2);
// // c2 = cross(pinf - p1, pinf - p2);
// // c3 = cross(p1 - p, p1 - pinf);
// // c4 = cross(p2 - p, p2 - pinf);

// if (c1 != c2 && c3 != c4) return true;

// // Line segments intersect each other
// // if (((c1 <= 0 && c2 >= 0) || (c1 >= 0 && c2 <= 0)) &&
// // ((c3 <= 0 && c4 >= 0) || (c3 >= 0 && c4 <= 0))) {
// // c++;
// // continue;
// // }

// // segments are colinear. We have to check if each point is
// // on top of the segment it is colinear to
// if (c1 == 0 && onSegment(p1, p, p2)) {
// return true;
// // break;
// }
// // will never happen
// if (c2 == 0 && onSegment(p1, pinf, p2)) {
// return true;
// // break;
// }

// if (c3 == 0 && onSegment(p, p1, pinf)) {
// return true;
// // break;
// }
// if (c4 == 0 && onSegment(p, p2, pinf)) {
// return true;
// // break;
// }
// return false;
// }

// Raycasting + checking if the point is on top of any edge with cross
// product
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x, y;
    while (cin >> n && n != 0) {
        vp v;
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            if (int(v.size()) > 0) {
                if (v[int(v.size()) - 1] != point(x, y)) v.pb(point(x, y));
            } else {
                v.pb(point(x, y));
            }
        }

        if (v[0] != v[int(v.size()) - 1]) v.pb(v[0]);  // Complete the polygon

        point p, p1, p2, pinf;
        cin >> m;
        bool on, off;
        int c;

        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            p = point(x, y);

            pinf = point(100000, imag(p));
            on = false;
            off = false;
            c = 0;

            for (int j = 1; j < int(v.size()); j++) {
                p1 = v[j - 1];
                p2 = v[j];

                if (intersect(p1, p2, p, pinf)) {
                    if (orientation(p1, p, p2) == 0) {
                        if (onSegment(p1, p, p2)) {
                            on = true;
                            break;
                        } else {
                            off = true;
                            break;
                        }
                    }

                    c++;
                }
            }

            if (on) {
                cout << "on" << endl;
            } else if (off) {
                cout << "out" << endl;
            } else if (c % 2 != 0) {
                cout << "in" << endl;
            } else {
                cout << "out" << endl;
            }
        }
    }

    return 0;
}
