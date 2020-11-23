#include <iostream>

using namespace std;

int main() {
    int n, l;
    cin >> n >> l;

    bool red;
    int d, r, g, t = 0, taux, lastDist = 0;
    for (int i = 0; i < n; i++) {
        cin >> d >> r >> g;
        red = true;

        t += d - lastDist;
        lastDist = d;

        taux = 0;
        while (taux < t || red) {
            if (red) {
                taux += r;
                red = false;
            } else {
                if (taux + g > t) {
                    g = t - taux;
                    taux += g;
                    break;
                }
                taux += g;
                red = true;
            }
        }

        t = taux;
    }

    cout << t + l - lastDist << endl;

    return 0;
}
