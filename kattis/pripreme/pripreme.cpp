#include <iostream>

using namespace std;

typedef long long ll;

int main() {
    ll n, aux;
    cin >> n;

    ll t = 0, a = -1;
    for(int i = 0; i < n; i++) {
        cin >> aux;
        t += aux;
        a = max(a, aux);
    }

    if(a > t - a) {
        cout << a * 2 << endl;
    } else {
        cout << t << endl;
    }

    return 0;
}
