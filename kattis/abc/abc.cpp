#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n[3];
    char c1, c2, c3;
    cin >> n[0] >> n[1] >> n[2] >> c1 >> c2 >> c3;

    sort(n, n + 3);

    cout << n[c1-65] << ' ' << n[c2-65] << ' ' << n[c3-65] << endl;

    return 0;
}
