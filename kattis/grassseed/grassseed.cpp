#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double c;
    cin >> c;

    int l;
    cin >> l;

    double total = 0;
    double wid, len;
    for (int i = 0; i < l; i++){
        cin >> wid >> len;

        total += wid * len * c;
    }

    cout << fixed;
    cout << setprecision(7);
    cout << total << endl;
    return 0;
}
