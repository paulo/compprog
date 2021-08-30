#include <bits/stdc++.h>

using namespace std;

typedef complex<int> point;
typedef vector<point> vp;

int cross(point(a), point(b)) {
    return (real(a)) * imag(b) - imag(a) * real(b);
}

double dist(point(a), point(b)) {
    return sqrt(((real(b) - real(a)) * (real(b) - real(a))) +
                ((imag(b) - imag(a)) * (imag(b) - imag(a))));
}

bool canIntersect(point(a1), point(a2), point(b1), point(b2)) {
    int minax = min(real(a1), real(a2));
    int minbx = min(real(b1), real(b2));
    int maxax = max(real(a1), real(a2));
    int maxbx = max(real(b1), real(b2));

    int minay = min(imag(a1), imag(a2));
    int minby = min(imag(b1), imag(b2));
    int maxay = max(imag(a1), imag(a2));
    int maxby = max(imag(b1), imag(b2));

    if (minax < minbx && maxax < minbx) return false;
    if (minbx < minax && maxbx < minax) return false;
    if (minay < minby && maxay < minby) return false;
    if (minby < minay && maxby < minay) return false;

    return true;
}

// check if p lies between p1 and p2
bool onSegment(point p, point p1, point p2) {
    int minx = min(real(p1), real(p2));
    int miny = min(imag(p1), imag(p2));
    int maxx = max(real(p1), real(p2));
    int maxy = max(imag(p1), imag(p2));

    return real(p) >= minx && real(p) <= maxx && imag(p) <= maxy &&
           imag(p) >= miny;
}

// Raycasting + checking if the point is on top of any edge with cross
// product
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cout << fixed;
    cout << setprecision(2);

    int n, x1, y1, x2, y2, x3, y3, x4, y4;
    point p1, p2, p3, p4;
    int c1, c2, c3, c4;
    double d;
    cin >> n;
    while (n-- > 0) {
        d = INT_MAX;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        cout << n << ": ";
        p1 = point(x1, y1);
        p2 = point(x2, y2);
        p3 = point(x3, y3);
        p4 = point(x4, y4);

        if (p1 == p2 || p3 == p4) {
            if (p1 == p2 && p3 == p4) {
                d = dist(p1, p3);
            } else if (p1 == p2) {
                d = abs(double(cross(p3 - p1, p4 - p1) / abs(p4 - p3)));
            } else {
                d = abs(double(cross(p1 - p4, p2 - p4) / abs(p2 - p1)));
            }
            cout << d << endl;
            continue;
        }

        c1 = cross(p3 - p1, p4 - p1);
        c2 = cross(p3 - p2, p4 - p2);
        c3 = cross(p2 - p3, p1 - p3);
        c4 = cross(p1 - p4, p1 - p4);

        if (((c1 <= 0 && c2 >= 0) || (c1 >= 0 && c2 <= 0)) &&  // intersects
            ((c3 <= 0 && c4 >= 0) || (c3 >= 0 && c4 <= 0))) {
            cout << 0.0 << endl;
            continue;
        }

        if (c1 == 0 && onSegment(p1, p3, p4)) {
            cout << 0.0 << endl;
            continue;
        } else if (c2 == 0 && onSegment(p2, p3, p4)) {
            cout << 0.0 << endl;
            continue;
        } else if (c3 == 0 && onSegment(p3, p1, p2)) {
            cout << 0.0 << endl;
            continue;
        } else if (c4 == 0 && onSegment(p4, p1, p2)) {
            cout << 0.0 << endl;
            continue;
        }
        // distance between p1 and p3-p4
        d = abs(double(cross(p3 - p1, p4 - p1) / abs(p4 - p3)));
        cout << d << endl;
        // distance between p2 and p3-p4
        d = abs(double(cross(p4 - p2, p3 - p2) / abs(p3 - p4)));
        cout << d << endl;
        // distance between p3 and p1-p2
        d = abs(double(cross(p1 - p3, p2 - p3) / abs(p2 - p1)));
        cout << d << endl;
        // distance between p4 and p1-p2
        d = abs(double(cross(p1 - p4, p2 - p4) / abs(p2 - p1)));

        cout << d << endl;
    }

    return 0;
}
