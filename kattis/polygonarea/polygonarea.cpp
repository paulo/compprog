#include <bits/stdc++.h>

using namespace std;

typedef complex<int> point;

int cross(point(a), point(b)) { return real(a) * imag(b) - imag(a) * real(b); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    while (cin >> n && n != 0) {
        vector<point> ps(n);
        for (int i = 0; i < n; i++) {
            cin >> x >> y;

            ps[i] = point(x, y);
        }

        cout << fixed;
        cout << setprecision(1);

        // shoelace formula
        // from wiki: The area formula is derived by taking each edge AB, and
        // calculating the area of triangle ABO with a vertex at the origin O,
        // by taking the cross-product (which gives the area of a parallelogram)
        // and dividing by 2. As one wraps around the polygon, these triangles
        // with positive and negative area will overlap, and the areas between
        // the origin and the polygon will be cancelled out and sum to 0, while
        // only the area inside the reference triangle remains. This is why the
        // formula is called the surveyor's formula, since the "surveyor" is at
        // the origin; if going counterclockwise, positive area is added when
        // going from left to right and negative area is added when going from
        // right to left, from the perspective of the origin.

        int trapArea = 0;
        for (int i = 0; i < n; i++) {
            trapArea += cross(ps[i % n], ps[(i + 1) % n]);
        }
        if (trapArea < 0)
            cout << "CW " << -trapArea / 2.0 << endl;
        else
            cout << "CCW " << trapArea / 2.0 << endl;
    }

    return 0;
}
