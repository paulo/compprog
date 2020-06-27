#include <iostream>
#include <complex>
#include <iomanip>

using namespace std;

#define PI 3.14159265
typedef complex<double> point;

int main() {
    int n, m;
    cin >> n;
    double angle, dist, x, y;

    for(int i = 0; i < n; i++){
        cin >> m;
        point last = point(0, 0);
        double aux = 90 * PI/180;
        for(int j = 0; j < m; j++){
            cin >> angle >> dist;

            aux+= (angle * PI/180);
            x = (dist * cos(aux)) + real(last);
            y = (dist * sin(aux)) + imag(last);

            last = point(x, y);
        }

        printf("%.6f %.6f\n",real(last), imag(last));
    }

    return 0;
}
