#include <bits/stdc++.h>

using namespace std;

typedef complex<float> point;
typedef vector<point> vp;

double cross(point a, point b) { return real(a) * imag(b) - imag(a) * real(b); }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n;

    float x, y;
    while (n-- > 0) {
        cin >> m;

        vp v(m);
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            v[i] = point(x, y);
        }

        float sum = 0;
        for (int i = 1; i <= m; i++) {
            sum += cross(v[i % m], v[(i - 1) % m]);
        }

        cout << abs(sum / 2) << endl;
    }

    return 0;
}
