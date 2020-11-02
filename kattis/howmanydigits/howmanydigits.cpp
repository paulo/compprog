#include <math.h>

#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 1000000;

// From https://math.stackexchange.com/questions/661227/factorial-length
int main() {
    double n;

    vector<double> v(MAXN + 1);
    for (int i = 1; i <= MAXN; i++) {
        v[i] = v[i - 1] + log10(i);
    }

    while (cin >> n) {
        cout << int(v[n]) + 1 << endl;
    }

    return 0;
}
