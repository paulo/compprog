#include <iostream>
#include <complex>
#include <vector>

using namespace std;

typedef complex<double> point;

double cross(point a, point b) { return real(a)*imag(b) - imag(a)*real(b); }
double ccw(point a, point b, point c) { return cross(b - a, c - b); }
double dot(point a, point b) { return real(a) * real(b) + imag(a) * imag(b); }
double angle(point a, point b, point c) { return acos(dot(b - a, c - b) / abs(b - a) / abs(c - b)); }

const int MAXN=700;

point hull[MAXN];

point lowesty = point(0,0);

struct cmp {
    bool operator() (const point& p1, const point& p2) const {
        point zerop = point(0,0);
        if(p1.second != p2.second) return p1.second > p2.second;

        return p1.first < p2.first;
    }
};

int convex_hull(vector<point> p) {
    int n = p.size(), l = 0;
    sort(p.begin(), p.end(), cmp());
    for (int i = 0; i < n; i++) {
        if (i > 0 && p[i] == p[i - 1]) continue;
        while (l >= 2 && ccw(hull[l - 2], hull[l - 1], p[i]) >= 0)
            l--;
        hull[l++] = p[i];
    }
    int r = l;
    for (int i = n - 2; i >= 0; i--) {
        if (p[i] == p[i + 1])
            continue;
        while (r - l >= 1 && ccw(hull[r - 2], hull[r - 1], p[i]) >= 0)
            r--;
        hull[r++] = p[i];
    }
    return l == 1 ? 1 : r - 1;
}

int main() {
    int n;
    cin >> n;

    int bs;
    for(int i = 0; i < n; i++){
        cin >> bs;

        float occupied = 0;
        vector<point> ps;
        point aux, p1, p2, p3, p4;
        double x, y, w, h, v;
        for(int j = 0; j < bs; j++){
            cin >> x >> y >> w >> h >> v;
            aux = point(x,y);


            p1 = point(h/2 * cos(v) + x, w/2 * sin(v) + y);
            p2 = point(-h/2 * cos(v) + x, w/2 * sin(v) + y);
            p3 = point(h/2 * cos(v) + x, -w/2 * sin(v) + y);
            p4 = point(-h/2 * cos(v) + x, -w/2 * sin(v) + y);

            if(lowesty == point(0,0)) lowesty = p1;
            if(imag(lowesty) > imag(p1)) lowesty = p1;
            if(imag(lowesty) > imag(p2)) lowesty = p2;
            if(imag(lowesty) > imag(p3)) lowesty = p3;
            if(imag(lowesty) > imag(p4)) lowesty = p4;

            cout << p1 << " " << p2 << " " << p3 << "" << p4 << endl;

            ps.push_back(p1);
            ps.push_back(p2);
            ps.push_back(p3);
            ps.push_back(p4);

            occupied+=w*h;
        }


    }


    // printf("%.1f\n", a);

    return 0;
}
