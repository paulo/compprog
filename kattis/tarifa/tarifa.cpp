#include <iostream>

using namespace std;

int main() {
    int x, n, a, t=0;
    cin >> x >> n;

    for(int i = 0; i < n; i++) {
        cin >> a;
        t += x - a;
    }

    cout << t+x << endl;
    return 0;
}
