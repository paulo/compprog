#include <iostream>
#include <complex>

using namespace std;

typedef complex<double> point;

double area(point p1, point p2, point p3) {
    return (real(p1)*(imag(p2) - imag(p3)) + real(p2)*(imag(p3) - imag(p1)) + real(p3) * (imag(p1) - imag(p2)))/2;
}

int main() {
    point p[3];
    double x,y;

    for(int i = 0; i < 3; i++){
        cin >> x >> y;
        p[i] = point(x,y);
    }

    double a = abs(area(p[0], p[1], p[2]));
    printf("%.1f\n", a);

    int n;
    cin >> n;

    int total = 0;
    point newp;
    for(int i = 0; i < n; i++){
        cin >> x >> y;

        double newa = 0;
        newp = point(x, y);

        newa += abs(area(p[0], p[1], newp));
        newa += abs(area(p[1], p[2], newp));
        newa += abs(area(p[2], p[0], newp));

        if(newa == a) total++;
    }

    cout << total << endl;

    return 0;
}
