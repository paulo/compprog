#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int t = 0, tt = 0, aux;
    for (int i = 0; i < n; i++) {
        cin >> aux;
        if (aux == -1) continue;
        t++;
        tt += aux;
    }

    cout << fixed;
    cout << setprecision(17);
    cout << double(tt) / double(t) << endl;

    return 0;
}
