#include <bits/stdc++.h>

using namespace std;

typedef complex<double> point;
typedef vector<point> vp;

bool ccw(point a, point b, point c) {
    return ((real(b) - real(a)) * (imag(c) - imag(a))) -
               ((imag(b) - imag(a)) * (real(c) - real(a))) >
           0;
}

struct cmp {
    bool operator()(const point &p1, const point &p2) const {
        if (real(p1) != real(p2)) return real(p1) < real(p2);

        return imag(p1) < imag(p2);
    }
};

point rotate(point piv, double angle, point p) {
    double s = sin(angle);
    double c = cos(angle);

    // translate point back to origin
    p.real(real(p) - real(piv));
    p.imag(imag(p) - imag(piv));

    // rotate point
    double xnew = real(p) * c + imag(p) * s;
    double ynew = imag(p) * c - real(p) * s;

    // translate point back:
    p.real(xnew + real(piv));
    p.imag(ynew + imag(piv));

    return p;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout << setprecision(7);

    int n, x, y;

    while (cin >> n) {
        vp v(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v[i] = point(x, y);
        }

        // Sort points according to x coordinates and then by y coordinates
        sort(v.begin(), v.end(), cmp());

        vp upperHull;
        upperHull.push_back(v[0]);
        upperHull.push_back(v[1]);

        // Go through the points and add each point to the hull. After adding
        // each point to the hull, we make sure that the last line segment in
        // the hull does not turn left. If it turns left, we repeatedly remove
        // the second last point from the hull
        for (int i = 2; i < n; i++) {
            while (upperHull.size() > 1 &&
                   !ccw(v[i], upperHull[upperHull.size() - 1],
                        upperHull[upperHull.size() - 2])) {
                upperHull.pop_back();
            }
            upperHull.push_back(v[i]);
        }

        vp lowerHull;
        lowerHull.push_back(v[v.size() - 1]);
        lowerHull.push_back(v[v.size() - 2]);

        for (int i = n - 2; i >= 0; i--) {
            while (lowerHull.size() > 1 &&
                   !ccw(v[i], lowerHull[lowerHull.size() - 1],
                        lowerHull[lowerHull.size() - 2])) {
                lowerHull.pop_back();
            }
            lowerHull.push_back(v[i]);
        }

        // Concat both hulls
        upperHull.insert(upperHull.end(), lowerHull.begin() + 1,
                         lowerHull.end() - 1);

        reverse(upperHull.begin(), upperHull.end());

        if (upperHull.size() > 1 &&
            upperHull[0] == upperHull[upperHull.size() - 1])
            upperHull.pop_back();

        // For every edge:
        // 1: find the angle with the X axis
        // 2: rotate every point around the first point of the edge for that
        // angle
        // 3: during iteration, save leftmost, rightmost, upmost, downmost
        double minP = INT_MAX;
        for (int i = 0; i < int(upperHull.size()); i++) {
            point a = upperHull[i % upperHull.size()];
            point b = upperHull[(i + 1) % upperHull.size()];

            // Angle formed by AB, relative to the X axis
            double angle = atan2(imag(b) - imag(a), real(b) - real(a));

            double minX = real(a), maxX = real(a);
            double minY = imag(a), maxY = imag(a);
            for (int j = 0; j < int(upperHull.size()) - 1; j++) {
                point c = upperHull[(j + i + 1) % upperHull.size()];
                c = rotate(a, angle, c);

                minX = min(minX, real(c));
                maxX = max(maxX, real(c));
                minY = min(minY, imag(c));
                maxY = max(maxY, imag(c));
            }

            minP = min(minP, 2 * (maxX - minX) + 2 * (maxY - minY));
        }

        cout << minP << endl;
    }

    return 0;
}
