#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;


    double display, reald, tdisplay=0, treald=0;
    for (int i = 0; i < n; i++) {
        cin >> display >> reald;
        tdisplay+=display; treald += reald;
    }

    if(treald / (tdisplay*60) <= 1.0) cout << "measurement error" << endl;
    else cout << setprecision(10) << treald / (tdisplay*60) << endl;
}
