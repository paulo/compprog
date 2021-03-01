#include <bits/stdc++.h>

using namespace std;

// typedef long long ll;
typedef complex<int> point;
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

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    while (cin >> n && n != 0) {
        vp v(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            v[i] = point(x, y);
        }

        if (n == 1) {
            cout << 1 << endl;
            cout << real(v[0]) << ' ' << imag(v[0]) << endl;
            continue;
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

        cout << upperHull.size() << endl;
        for (int i = 0; i < int(upperHull.size()); i++) {
            cout << real(upperHull[i]) << ' ' << imag(upperHull[i]) << endl;
        }
    }

    return 0;
}
