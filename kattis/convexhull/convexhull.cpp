#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef complex<int> point;
typedef vector<point> vp;

// NOTE: There's an edge case hidden around here which I'm failing to debug
// I've managed to do it with Andrew's algorithm, which is on this folder

int cross(point a, point b) { return real(a) * imag(b) - imag(a) * real(b); }

// Graham's scan algorithm:
// • Pick the point p0 with the lowest y coordinate (and lowest x coordinate if
// lowY is duplicate) • Sort all the points by polar angle with p0. (p0 acts as
// origin)
//      - This can be done by checking the cross product of 3 points.
//      - The cross product should be positive, meaning that the
//      - points are in ccw order and therefore p2 is to the left
//      - of p1 (relative to p0). If coolinear, choose the one furthest
//      - from p0
// • Iterate through all the points
// • If the current point forms a clockwise angle with the last two points,
// remove last point from the convex set.
// • Otherwise, add the current point to the convex set.

point lowY = point(INT_MAX, INT_MAX);

int dist(point p1, point p2) {
    return (real(p1) - real(p2)) * (real(p1) - real(p2)) +
           (imag(p1) - imag(p2)) * (imag(p1) - imag(p2));
}

int orientation(point p, point q, point r) {
    int val = (imag(q) - imag(p)) * (real(r) - real(q)) -
              (real(q) - real(p)) * (imag(r) - imag(q));
    if (val == 0) return 0;    // colinear
    return (val > 0) ? 1 : 2;  // clock or counterclock wise
}

// A function used by library function qsort() to sort an array of
// points with respect to the first point
int compare(const void *vp1, const void *vp2) {
    point *p1 = (point *)vp1;
    point *p2 = (point *)vp2;
    // Find orientation
    int o = orientation(lowY, *p1, *p2);
    if (o == 0) return (dist(lowY, *p2) >= dist(lowY, *p1)) ? -1 : 1;
    return (o == 2) ? -1 : 1;
}

struct cmp {
    bool operator()(const point &p1, const point &p2) const {
        // Find orientation
        int o = orientation(lowY, p1, p2);
        if (o == 0) return dist(lowY, p2) > dist(lowY, p1);
        return o == 2;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y, lowInd = 0;
    while (cin >> n && n != 0) {
        vp v(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v[i] = point(x, y);

            if (imag(lowY) > imag(v[i])) {
                lowY = v[i];
                lowInd = i;
            } else if (imag(lowY) == imag(v[i]) && real(lowY) > real(v[i])) {
                lowY = v[i];
                lowInd = i;
            }
        }

        if (n == 1) {
            cout << 1 << endl << real(v[0]) << ' ' << imag(v[0]) << endl;
            continue;
        }

        // Sort maintaining low point at the beginning
        swap(v[0], v[lowInd]);
        sort(v.begin() + 1, v.end(), cmp());

        // Remove colinear points with lowY, keeping only the farthest one
        // (sorted by distance already before). This removes duplicates as well
        int m = 1;
        for (int i = 1; i < n; i++) {
            while (i < n - 1 && orientation(lowY, v[i], v[i + 1]) == 0) i++;
            v[m] = v[i];
            m++;
        }

        vp convex;
        if (m > 0) convex.push_back(v[0]);
        if (m > 1) convex.push_back(v[1]);

        for (int i = convex.size(); i < m; i++) {
            while (convex.size() > 1 &&
                   orientation(convex[convex.size() - 2],
                               convex[convex.size() - 1], v[i]) != 2) {
                convex.pop_back();
            }

            convex.push_back(v[i]);
        }

        if (convex.size() > 1 && convex[0] == convex[convex.size() - 1])
            convex.pop_back();

        cout << convex.size() << endl;
        for (int i = 0; i < int(convex.size()); i++) {
            cout << real(convex[i]) << ' ' << imag(convex[i]) << endl;
        }
    }

    return 0;
}

