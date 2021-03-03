#include <bits/stdc++.h>

using namespace std;

typedef complex<double> point;
typedef vector<point> vp;

double cross(point(a), point(b)) {
    return real(a) * imag(b) - imag(a) * real(b);
}

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

vp convex_hull(vp v) {
    if (int(v.size()) <= 1) return v;

    // Sort points according to x coordinates and then by y coordinates
    sort(v.begin(), v.end(), cmp());

    vp upperHull;
    upperHull.push_back(v[0]);
    upperHull.push_back(v[1]);

    // Go through the points and add each point to the hull. After adding
    // each point to the hull, we make sure that the last line segment in
    // the hull does not turn left. If it turns left, we repeatedly remove
    // the second last point from the hull
    for (int i = 2; i < int(v.size()); i++) {
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

    for (int i = v.size() - 2; i >= 0; i--) {
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

    // Remove possible duplicate
    if (upperHull.size() > 1 && upperHull[0] == upperHull[upperHull.size() - 1])
        upperHull.pop_back();

    return upperHull;
}

int main() {
    int n;
    cin >> n;
    cout << fixed;
    cout << setprecision(1);

    int bs;
    for (int i = 0; i < n; i++) {
        cin >> bs;

        double occupied = 0;
        vp ps;
        point aux, p1, p2, p3, p4;
        double x, y, w, h, vr, v;
        for (int j = 0; j < bs; j++) {
            cin >> x >> y >> w >> h >> v;
            aux = point(x, y);
            vr = v * M_PI / 180;  // angle in radians

            p1 = point(x - w / 2, y + h / 2);  // upper left
            p2 = point(x + w / 2, y + h / 2);  // upper right
            p3 = point(x - w / 2, y - h / 2);  // down left
            p4 = point(x + w / 2, y - h / 2);  // down right

            p1 = rotate(aux, vr, p1);
            p2 = rotate(aux, vr, p2);
            p3 = rotate(aux, vr, p3);
            p4 = rotate(aux, vr, p4);

            ps.push_back(p1);
            ps.push_back(p2);
            ps.push_back(p3);
            ps.push_back(p4);

            occupied += w * h;
        }

        vp hull = convex_hull(ps);
        double hullArea = 0;
        for (int j = 0; j < int(hull.size()); j++) {
            hullArea +=
                cross(hull[j % hull.size()], hull[(j + 1) % hull.size()]);
        }

        cout << (occupied * 2 / hullArea) * 100.0 << " %" << endl;
    }

    return 0;
}
