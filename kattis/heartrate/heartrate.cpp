#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << fixed;
    cout << setprecision(4);

    double b, p;
    for(int i = 0; i < n; i++) {
        cin >> b >> p;

        double bpm = 60 * b / p;
        double var = 60  / p;


        cout << bpm - var  << ' ' << bpm << ' ' << bpm + var << endl;
    }

    return 0;
}
